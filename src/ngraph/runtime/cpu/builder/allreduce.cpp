//*****************************************************************************
// Copyright 2017-2019 Intel Corporation
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

#include "ngraph/op/allreduce.hpp"
#include "ngraph/log.hpp"
#include "ngraph/runtime/cpu/cpu_builder.hpp"

using namespace std;
using namespace ngraph;

namespace ngraph
{
    namespace runtime
    {
        namespace cpu
        {
            template <>
            void Builder::BUILDER_DECL(ngraph::op::AllReduce)
            {
                static int call_seq = 0;

                auto& functors = external_function->get_functors();
                auto& arg_tensor = external_function->get_tensor_data(args[0].get_name());
                auto& out_tensor = external_function->get_tensor_data(out[0].get_name());
                auto count = static_cast<int>(out[0].get_size());
                auto data_type = args[0].get_element_type().get_type_enum();

                auto external_function_name = external_function->get_function_name();
                NGRAPH_DEBUG_PRINT(
                    "AllReduce Queued[%d]: Function: %s Node: %s %s Size: "
                    "%d",
                    call_seq,
                    external_function_name.c_str(),
                    node->get_name().c_str(),
                    node->get_friendly_name().c_str(),
                    count);

                auto functor = [&, count, data_type](CPURuntimeContext* ctx,
                                                     CPUExecutionContext* ectx) {
                    get_distributed_interface()->all_reduce(
                        arg_tensor, out_tensor, data_type, count);
                };
                functors.emplace_back(functor);
            }

            REGISTER_OP_BUILDER(AllReduce);
        }
    }
}
