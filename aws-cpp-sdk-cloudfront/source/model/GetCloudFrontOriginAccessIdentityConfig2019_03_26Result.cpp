﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/cloudfront/model/GetCloudFrontOriginAccessIdentityConfig2019_03_26Result.h>
#include <aws/core/utils/xml/XmlSerializer.h>
#include <aws/core/AmazonWebServiceResult.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>

#include <utility>

using namespace Aws::CloudFront::Model;
using namespace Aws::Utils::Xml;
using namespace Aws::Utils;
using namespace Aws;

GetCloudFrontOriginAccessIdentityConfig2019_03_26Result::GetCloudFrontOriginAccessIdentityConfig2019_03_26Result()
{
}

GetCloudFrontOriginAccessIdentityConfig2019_03_26Result::GetCloudFrontOriginAccessIdentityConfig2019_03_26Result(const AmazonWebServiceResult<XmlDocument>& result)
{
  *this = result;
}

GetCloudFrontOriginAccessIdentityConfig2019_03_26Result& GetCloudFrontOriginAccessIdentityConfig2019_03_26Result::operator =(const AmazonWebServiceResult<XmlDocument>& result)
{
  const XmlDocument& xmlDocument = result.GetPayload();
  XmlNode resultNode = xmlDocument.GetRootElement();

  if(!resultNode.IsNull())
  {
    m_cloudFrontOriginAccessIdentityConfig = resultNode;
  }

  const auto& headers = result.GetHeaderValueCollection();
  const auto& eTagIter = headers.find("etag");
  if(eTagIter != headers.end())
  {
    m_eTag = eTagIter->second;
  }

  return *this;
}
