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

// This collection contains one entry for each op. If an op is added it must be
// added to this list.
//
// In order to use this list you want to define a macro named exactly NGRAPH_OP
// When you are done you should undef the macro
// As an example if you wanted to make a list of all op names as strings you could do this:
//
// #define NGRAPH_OP(a,b) #a,
// std::vector<std::string> op_names{
// #include "this include file name"
// };
// #undef NGRAPH_OP
//
// This sample expands to a list like this:
// "Abs",
// "Acos",
// ...
//
// #define NGRAPH_OP(a,b) b::a,
// std::vector<std::string> op_names{
// #include "this include file name"
// };
// #undef NGRAPH_OP
//
// This sample expands to a list like this:
// ngraph::op::v0::Abs,
// ngraph::op::v0::Acos,
// ...
//
// It's that easy. You can use this for fun and profit.

#ifndef NGRAPH_OP
#warning "NGRAPH_OP not defined"
#define NGRAPH_OP(x, y)
#endif

NGRAPH_OP(Abs, ngraph::op::v0)
NGRAPH_OP(Acos, ngraph::op::v0)
NGRAPH_OP(Add, ngraph::op::v1)
NGRAPH_OP(All, ngraph::op::v0)
NGRAPH_OP(AllReduce, ngraph::op::v0)
NGRAPH_OP(Any, ngraph::op::v0)
NGRAPH_OP(ArgMax, ngraph::op::v0)
NGRAPH_OP(ArgMin, ngraph::op::v0)
NGRAPH_OP(Asin, ngraph::op::v0)
NGRAPH_OP(Atan, ngraph::op::v0)
NGRAPH_OP(Atan2, ngraph::op::v0)
NGRAPH_OP(AvgPool, ngraph::op::v0)
NGRAPH_OP(AvgPoolBackprop, ngraph::op::v0)
NGRAPH_OP(BatchMatMul, ngraph::op::v0)
NGRAPH_OP(BatchMatMulTranspose, ngraph::op::v0)
NGRAPH_OP(BatchNormInference, ngraph::op::v0)
NGRAPH_OP(BatchNormTraining, ngraph::op::v0)
NGRAPH_OP(BatchNormTrainingBackprop, ngraph::op::v0)
NGRAPH_OP(Broadcast, ngraph::op::v0)
NGRAPH_OP(BroadcastDistributed, ngraph::op::v0)
NGRAPH_OP(BroadcastLike, ngraph::op::v0)
NGRAPH_OP(Ceiling, ngraph::op::v0)
NGRAPH_OP(Clamp, ngraph::op::v0)
NGRAPH_OP(Concat, ngraph::op::v0)
NGRAPH_OP(Constant, ngraph::op::v0)
NGRAPH_OP(Convert, ngraph::op::v0)
NGRAPH_OP(Convolution, ngraph::op::v0)
NGRAPH_OP(ConvolutionBackpropData, ngraph::op::v0)
NGRAPH_OP(ConvolutionBackpropFilters, ngraph::op::v0)
NGRAPH_OP(ConvolutionBias, ngraph::op::v0)
NGRAPH_OP(ConvolutionBiasAdd, ngraph::op::v0)
NGRAPH_OP(ConvolutionBiasBackpropFiltersBias, ngraph::op::v0)
NGRAPH_OP(Cos, ngraph::op::v0)
NGRAPH_OP(Cosh, ngraph::op::v0)
NGRAPH_OP(CropAndResize, ngraph::op::v0)
NGRAPH_OP(CrossEntropy, ngraph::op::v0)
NGRAPH_OP(CrossEntropyBackprop, ngraph::op::v0)
NGRAPH_OP(CumSum, ngraph::op::v0)
NGRAPH_OP(DepthToSpace, ngraph::op::v0)
NGRAPH_OP(Dequantize, ngraph::op::v0)
NGRAPH_OP(Divide, ngraph::op::v1)
NGRAPH_OP(Dot, ngraph::op::v0)
NGRAPH_OP(DynBroadcast, ngraph::op::v0)
NGRAPH_OP(DynPad, ngraph::op::v0)
NGRAPH_OP(DynReplaceSlice, ngraph::op::v0)
NGRAPH_OP(DynSlice, ngraph::op::v0)
NGRAPH_OP(Elu, ngraph::op::v0)
NGRAPH_OP(EmbeddingLookup, ngraph::op::v0)
NGRAPH_OP(Equal, ngraph::op::v1)
NGRAPH_OP(Erf, ngraph::op::v0)
NGRAPH_OP(Exp, ngraph::op::v0)
NGRAPH_OP(FakeQuantize, ngraph::op::v0)
NGRAPH_OP(Floor, ngraph::op::v0)
NGRAPH_OP(Gather, ngraph::op::v0)
NGRAPH_OP(GatherND, ngraph::op::v0)
NGRAPH_OP(Gelu, ngraph::op::v0)
NGRAPH_OP(GeluBackpropFactor, ngraph::op::v0)
NGRAPH_OP(Gemm, ngraph::op::v0)
NGRAPH_OP(GenerateMask, ngraph::op::v0)
NGRAPH_OP(Greater, ngraph::op::v1)
NGRAPH_OP(GreaterEqual, ngraph::op::v1)
NGRAPH_OP(GRN, ngraph::op::v0)
NGRAPH_OP(GroupConvolution, ngraph::op::v0)
NGRAPH_OP(GroupConvolutionBackpropData, ngraph::op::v0)
NGRAPH_OP(GroupConvolutionBackpropFilters, ngraph::op::v0)
NGRAPH_OP(GRUCell, ngraph::op::v3)
NGRAPH_OP(HardSigmoid, ngraph::op::v0)
NGRAPH_OP(Interpolate, ngraph::op::v0)
NGRAPH_OP(LayerNorm, ngraph::op::v0)
NGRAPH_OP(LayerNormBackprop, ngraph::op::v0)
NGRAPH_OP(Less, ngraph::op::v1)
NGRAPH_OP(LessEqual, ngraph::op::v1)
NGRAPH_OP(Log, ngraph::op::v0)
NGRAPH_OP(LogicalAnd, ngraph::op::v1)
NGRAPH_OP(LogicalNot, ngraph::op::v1)
NGRAPH_OP(LogicalOr, ngraph::op::v1)
NGRAPH_OP(LogicalXor, ngraph::op::v1)
NGRAPH_OP(LRN, ngraph::op::v0)
NGRAPH_OP(LSTMCell, ngraph::op::v0)
NGRAPH_OP(LSTMSequence, ngraph::op::v0)
NGRAPH_OP(MatMul, ngraph::op::v0)
NGRAPH_OP(Max, ngraph::op::v0)
NGRAPH_OP(Maximum, ngraph::op::v1)
NGRAPH_OP(MaxPool, ngraph::op::v0)
NGRAPH_OP(MaxPoolBackprop, ngraph::op::v0)
NGRAPH_OP(Min, ngraph::op::v0)
NGRAPH_OP(Minimum, ngraph::op::v1)
NGRAPH_OP(Multiply, ngraph::op::v1)
NGRAPH_OP(MVN, ngraph::op::v0)
NGRAPH_OP(Negative, ngraph::op::v0)
NGRAPH_OP(NormalizeL2, ngraph::op::v0)
NGRAPH_OP(NotEqual, ngraph::op::v1)
NGRAPH_OP(OneHot, ngraph::op::v0)
NGRAPH_OP(Pad, ngraph::op::v0)
NGRAPH_OP(Parameter, ngraph::op::v0)
NGRAPH_OP(PartialSlice, ngraph::op::v0)
NGRAPH_OP(PartialSliceBackprop, ngraph::op::v0)
NGRAPH_OP(Passthrough, ngraph::op::v0)
NGRAPH_OP(Power, ngraph::op::v1)
NGRAPH_OP(PRelu, ngraph::op::v0)
NGRAPH_OP(Product, ngraph::op::v0)
NGRAPH_OP(Quantize, ngraph::op::v0)
NGRAPH_OP(QuantizedConvolution, ngraph::op::v0)
NGRAPH_OP(QuantizedConvolutionBias, ngraph::op::v0)
NGRAPH_OP(QuantizedConvolutionBiasAdd, ngraph::op::v0)
NGRAPH_OP(QuantizedConvolutionBiasSignedAdd, ngraph::op::v0)
NGRAPH_OP(QuantizedConvolutionRelu, ngraph::op::v0)
NGRAPH_OP(QuantizedDot, ngraph::op::v0)
NGRAPH_OP(QuantizedDotBias, ngraph::op::v0)
NGRAPH_OP(RandomUniform, ngraph::op::v0)
NGRAPH_OP(Range, ngraph::op::v0)
NGRAPH_OP(Recv, ngraph::op::v0)
NGRAPH_OP(Relu, ngraph::op::v0)
NGRAPH_OP(ReluBackprop, ngraph::op::v0)
NGRAPH_OP(ReplaceSlice, ngraph::op::v0)
NGRAPH_OP(Reshape, ngraph::op::v0)
NGRAPH_OP(Result, ngraph::op::v0)
NGRAPH_OP(Reverse, ngraph::op::v0)
NGRAPH_OP(ReverseSequence, ngraph::op::v0)
NGRAPH_OP(RNNCell, ngraph::op::v0)
NGRAPH_OP(Round, ngraph::op::v0)
NGRAPH_OP(ScalarConstantLike, ngraph::op::v0)
NGRAPH_OP(ScaleShift, ngraph::op::v0)
NGRAPH_OP(ScatterAdd, ngraph::op::v0)
NGRAPH_OP(ScatterND, ngraph::op::v0)
NGRAPH_OP(ScatterNDAdd, ngraph::op::v0)
NGRAPH_OP(Select, ngraph::op::v0)
NGRAPH_OP(Selu, ngraph::op::v0)
NGRAPH_OP(Send, ngraph::op::v0)
NGRAPH_OP(ShapeOf, ngraph::op::v0)
NGRAPH_OP(ShuffleChannels, ngraph::op::v0)
NGRAPH_OP(Sigmoid, ngraph::op::v0)
NGRAPH_OP(SigmoidBackprop, ngraph::op::v0)
NGRAPH_OP(Sign, ngraph::op::v0)
NGRAPH_OP(Sin, ngraph::op::v0)
NGRAPH_OP(Sinh, ngraph::op::v0)
NGRAPH_OP(Slice, ngraph::op::v0)
NGRAPH_OP(Softmax, ngraph::op::v0)
NGRAPH_OP(SoftmaxCrossEntropy, ngraph::op::v0)
NGRAPH_OP(SoftmaxCrossEntropyBackprop, ngraph::op::v0)
NGRAPH_OP(SpaceToDepth, ngraph::op::v0)
NGRAPH_OP(Split, ngraph::op::v0)
NGRAPH_OP(Sqrt, ngraph::op::v0)
NGRAPH_OP(SquaredDifference, ngraph::op::v0)
NGRAPH_OP(Squeeze, ngraph::op::v0)
NGRAPH_OP(Stack, ngraph::op::v0)
NGRAPH_OP(StopGradient, ngraph::op::v0)
NGRAPH_OP(Subtract, ngraph::op::v1)
NGRAPH_OP(Sum, ngraph::op::v0)
NGRAPH_OP(Tan, ngraph::op::v0)
NGRAPH_OP(Tanh, ngraph::op::v0)
NGRAPH_OP(TensorIterator, ngraph::op::v0)
NGRAPH_OP(Tile, ngraph::op::v0)
NGRAPH_OP(TopK, ngraph::op::v0)
NGRAPH_OP(Unsqueeze, ngraph::op::v0)
