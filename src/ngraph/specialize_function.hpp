//*****************************************************************************
// Copyright 2017-2020 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//*****************************************************************************

#pragma once

#include "ngraph/function.hpp"

namespace ngraph
{
    /// \brief Creates a "specialized" clone of a function. The partial shapes and element types of
    ///        the function's parameters may be narrowed to more specific shapes and element types,
    ///        and constant values may optionally be substituted for any or all of the parameters.
    /// \param f The function to be cloned.
    /// \param parameter_element_types The new parameter element types to substitute. Length must
    ///          be equal to the number of parameters of f.
    /// \param parameter_shapes The new parameter shapes to substitute. Length must be equal to the
    ///          number of parameters of f.
    /// \param parameter_values Parameter values to substitute. Length must be equal to the number
    ///          of parameters of f, with nullptr indicating that no substitution is to be made for
    ///          the corresponding parameter.
    /// \return A clone of f, with the parameter element types, shapes, and values specialized.
    /// \throws CheckFailure if parameter_element_types, parameter_shapes is not valid
    ///         (see details).
    /// \throws NodeValidationError if node validation fails as the clone is being constructed.
    ///
    /// Creates a "specialized" clone of an nGraph Function.
    ///
    /// For example, suppose that a function f has three parameters with partial shapes:
    ///
    /// ```
    /// param0: ?
    /// param1: {1,?,3}
    /// param2: {?,?,4}
    /// ```
    ///
    /// Shape specialization would allow us to create a clone of f where the shapes are (for
    /// example):
    ///
    /// ```
    /// param0: {1,2}
    /// param1: {1,5,3}
    /// param2: {3,?,4}
    /// ```
    ///
    /// But not (for example):
    ///
    /// ```
    /// param1: {1,5,3,4}  // rank doesn't match {1,?,3}
    /// param1: {2,?,3}    // the "2" doesn't match the "1"
    /// param1: {?,?,3}    // the new shape is too relaxed: it doesn't require 1 for the first dim
    /// ```
    ///
    /// Note that validation errors can potentially occur during cloning. For example:
    ///
    /// ```
    /// n = Parameter{shape=?}
    /// m = Parameter{shape=?}
    /// x = n + m
    /// f = Function(x,{n,m})
    /// ```
    ///
    /// If we specialize n to the shape `{1,2,3}` and m to the shape `{4,5,6}`, cloning will fail
    /// because when we reconstruct the new x node, it will see that the shapes are inconsistent
    /// for elementwise add.
    ///
    /// Specialization of element types is also possible: `element::dynamic` can be specialized
    /// to a concrete element type or left dynamic; but a concrete element type can only be
    /// specialized to itself (e.g., specialization does not allow you to change `element::i32`
    /// to `element::i64`).
    ///
    /// Finally, it is possible to specialize parameter values. If the ith element of
    /// `parameter_values` is not `nullptr`, and fully static element type and shape has been
    /// specified for the ith parameter, a `Constant` node will be created and substituted for the
    /// ith parameter, with its data drawn from `parameter_values[i]`. Note that the Parameter node
    /// remains (in order to maintain the arity of the function), but will no longer have any
    /// users.
    ///
    /// It is required that:
    ///    1. The length of parameter_element_types, parameter_shapes, and parameter_values is the
    ///       same as the number of f's parameters.
    ///    2. Each shape in parameter_shapes is a refinement of the shape of the corresponding
    ///       parameter of f. Roughly speaking, a shape s1 is said to "refine" s2 if s1 can be
    ///       obtained from s2 by filling in s2's question marks. See PartialShape::refines for
    ///       more details.
    ///    3. For all i, either the element type of fp_i is dynamic, or fp_i is the same as
    ///       parameter_element_types[i]. (Here fp_i is the ith parameter of f.)
    ///    4. For all i where parameter_values[i] != nullptr and parameter_element_types[i] is
    ///       static and parameter_shapes[i] is static, parameter_values[i] points to a buffer from
    ///       which a Constant node with element type parameter_element_types[i] and shape
    ///       parameter_shapes[i] can be created.
    ///
    /// TODO(amprocte): convert this to a pass.
    NGRAPH_API
    std::shared_ptr<Function>
        specialize_function(std::shared_ptr<Function> f,
                            const std::vector<element::Type>& parameter_element_types,
                            const std::vector<PartialShape>& parameter_shapes,
                            const std::vector<void*>& parameter_values);

    /// \brief Creates a "specialized" clone of a function. The partial shapes and element types of
    ///        the function's parameters may be narrowed to more specific shapes and element types,
    ///        and constant values may optionally be substituted for any or all of the parameters.
    /// \param f The function to be cloned.
    /// \param parameter_element_types The new parameter element types to substitute. Length must
    ///          be equal to the number of parameters of f.
    /// \param parameter_shapes The new parameter shapes to substitute. Length must be equal to the
    ///          number of parameters of f.
    /// \param parameter_values Parameter values to substitute. Length must be equal to the number
    ///          of parameters of f, with nullptr indicating that no substitution is to be made for
    ///          the corresponding parameter.
    /// \param constant_folding If flag is true, constant propagation is applied
    /// \param share_constants If flag is true, cloned function will have shared constants with
    ///          original function.
    /// \return A clone of f, with the parameter element types, shapes, and values specialized.
    /// \throws CheckFailure if parameter_element_types, parameter_shapes is not valid
    ///         (see details).
    /// \throws NodeValidationError if node validation fails as the clone is being constructed.
    ///
    /// Creates a "specialized" clone of an nGraph Function.
    ///
    /// For example, suppose that a function f has three parameters with partial shapes:
    ///
    /// ```
    /// param0: ?
    /// param1: {1,?,3}
    /// param2: {?,?,4}
    /// ```
    ///
    /// Shape specialization would allow us to create a clone of f where the shapes are (for
    /// example):
    ///
    /// ```
    /// param0: {1,2}
    /// param1: {1,5,3}
    /// param2: {3,?,4}
    /// ```
    ///
    /// But not (for example):
    ///
    /// ```
    /// param1: {1,5,3,4}  // rank doesn't match {1,?,3}
    /// param1: {2,?,3}    // the "2" doesn't match the "1"
    /// param1: {?,?,3}    // the new shape is too relaxed: it doesn't require 1 for the first dim
    /// ```
    ///
    /// Note that validation errors can potentially occur during cloning. For example:
    ///
    /// ```
    /// n = Parameter{shape=?}
    /// m = Parameter{shape=?}
    /// x = n + m
    /// f = Function(x,{n,m})
    /// ```
    ///
    /// If we specialize n to the shape `{1,2,3}` and m to the shape `{4,5,6}`, cloning will fail
    /// because when we reconstruct the new x node, it will see that the shapes are inconsistent
    /// for elementwise add.
    ///
    /// Specialization of element types is also possible: `element::dynamic` can be specialized
    /// to a concrete element type or left dynamic; but a concrete element type can only be
    /// specialized to itself (e.g., specialization does not allow you to change `element::i32`
    /// to `element::i64`).
    ///
    /// Finally, it is possible to specialize parameter values. If the ith element of
    /// `parameter_values` is not `nullptr`, and fully static element type and shape has been
    /// specified for the ith parameter, a `Constant` node will be created and substituted for the
    /// ith parameter, with its data drawn from `parameter_values[i]`. Note that the Parameter node
    /// remains (in order to maintain the arity of the function), but will no longer have any
    /// users.
    ///
    /// It is required that:
    ///    1. The length of parameter_element_types, parameter_shapes, and parameter_values is the
    ///       same as the number of f's parameters.
    ///    2. Each shape in parameter_shapes is a refinement of the shape of the corresponding
    ///       parameter of f. Roughly speaking, a shape s1 is said to "refine" s2 if s1 can be
    ///       obtained from s2 by filling in s2's question marks. See PartialShape::refines for
    ///       more details.
    ///    3. For all i, either the element type of fp_i is dynamic, or fp_i is the same as
    ///       parameter_element_types[i]. (Here fp_i is the ith parameter of f.)
    ///    4. For all i where parameter_values[i] != nullptr and parameter_element_types[i] is
    ///       static and parameter_shapes[i] is static, parameter_values[i] points to a buffer from
    ///       which a Constant node with element type parameter_element_types[i] and shape
    ///       parameter_shapes[i] can be created.
    ///
    /// TODO(amprocte): convert this to a pass.
    NGRAPH_API
    std::shared_ptr<Function>
        specialize_function(std::shared_ptr<Function> f,
                            const std::vector<element::Type>& parameter_element_types,
                            const std::vector<PartialShape>& parameter_shapes,
                            const std::vector<void*>& parameter_values,
                            bool constant_folding,
                            bool share_constants);
}
