﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/cloudfront/model/GetStreamingDistribution2019_03_26Request.h>
#include <aws/core/utils/xml/XmlSerializer.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>

#include <utility>

using namespace Aws::CloudFront::Model;
using namespace Aws::Utils::Xml;
using namespace Aws::Utils;

GetStreamingDistribution2019_03_26Request::GetStreamingDistribution2019_03_26Request() : 
    m_idHasBeenSet(false)
{
}

Aws::String GetStreamingDistribution2019_03_26Request::SerializePayload() const
{
  return {};
}


