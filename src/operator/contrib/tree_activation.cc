/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

/*!
 * Copyright (c) 2017 Microsoft
 * Licensed under The Apache-2.0 License [see LICENSE for details]
 * \file tree_activation.cc
 * \brief
 * \author Xizhou Zhu
*/

#include "./tree_activation-inl.h"


namespace mxnet {
namespace op {

template<typename xpu>
class TreeActivationOp : public Operator{
 public:
  explicit TreeActivationOp(TreeActivationParam param) {
    this->param_ = param;
  }

  virtual void Forward(const OpContext &ctx,
                       const std::vector<TBlob> &in_data,
                       const std::vector<OpReqType> &req,
                       const std::vector<TBlob> &out_data,
                       const std::vector<TBlob> &aux_states) {
    LOG(FATAL) << "not implemented";
  }

  virtual void Backward(const OpContext &ctx,
                        const std::vector<TBlob> &out_grad,
                        const std::vector<TBlob> &in_data,
                        const std::vector<TBlob> &out_data,
                        const std::vector<OpReqType> &req,
                        const std::vector<TBlob> &in_grad,
                        const std::vector<TBlob> &aux_states) {
    LOG(FATAL) << "not implemented";
  }

 private:
  TreeActivationParam param_;
};  // class TreeActivationOp

template<>
Operator *CreateOp<cpu>(TreeActivationParam param) {
  return new TreeActivationOp<cpu>(param);
}

Operator* TreeActivationProp::CreateOperator(Context ctx) const {
  DO_BIND_DISPATCH(CreateOp, param_);
}

DMLC_REGISTER_PARAMETER(TreeActivationParam);

MXNET_REGISTER_OP_PROPERTY(_contrib_TreeActivation, TreeActivationProp)
.describe("Tree Activation")
.add_argument("data", "NDArray-or-Symbol", "Input feature maps.")
.add_arguments(TreeActivationParam::__FIELDS__());

}  // namespace op
}  // namespace mxnet
