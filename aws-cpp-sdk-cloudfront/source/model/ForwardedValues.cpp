﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/cloudfront/model/ForwardedValues.h>
#include <aws/core/utils/xml/XmlSerializer.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>

#include <utility>

using namespace Aws::Utils::Xml;
using namespace Aws::Utils;

namespace Aws
{
namespace CloudFront
{
namespace Model
{

ForwardedValues::ForwardedValues() : 
    m_queryString(false),
    m_queryStringHasBeenSet(false),
    m_cookiesHasBeenSet(false),
    m_headersHasBeenSet(false),
    m_queryStringCacheKeysHasBeenSet(false)
{
}

ForwardedValues::ForwardedValues(const XmlNode& xmlNode) : 
    m_queryString(false),
    m_queryStringHasBeenSet(false),
    m_cookiesHasBeenSet(false),
    m_headersHasBeenSet(false),
    m_queryStringCacheKeysHasBeenSet(false)
{
  *this = xmlNode;
}

ForwardedValues& ForwardedValues::operator =(const XmlNode& xmlNode)
{
  XmlNode resultNode = xmlNode;

  if(!resultNode.IsNull())
  {
    XmlNode queryStringNode = resultNode.FirstChild("QueryString");
    if(!queryStringNode.IsNull())
    {
      m_queryString = StringUtils::ConvertToBool(StringUtils::Trim(Aws::Utils::Xml::DecodeEscapedXmlText(queryStringNode.GetText()).c_str()).c_str());
      m_queryStringHasBeenSet = true;
    }
    XmlNode cookiesNode = resultNode.FirstChild("Cookies");
    if(!cookiesNode.IsNull())
    {
      m_cookies = cookiesNode;
      m_cookiesHasBeenSet = true;
    }
    XmlNode headersNode = resultNode.FirstChild("Headers");
    if(!headersNode.IsNull())
    {
      m_headers = headersNode;
      m_headersHasBeenSet = true;
    }
    XmlNode queryStringCacheKeysNode = resultNode.FirstChild("QueryStringCacheKeys");
    if(!queryStringCacheKeysNode.IsNull())
    {
      m_queryStringCacheKeys = queryStringCacheKeysNode;
      m_queryStringCacheKeysHasBeenSet = true;
    }
  }

  return *this;
}

void ForwardedValues::AddToNode(XmlNode& parentNode) const
{
  Aws::StringStream ss;
  if(m_queryStringHasBeenSet)
  {
   XmlNode queryStringNode = parentNode.CreateChildElement("QueryString");
   ss << std::boolalpha << m_queryString;
   queryStringNode.SetText(ss.str());
   ss.str("");
  }

  if(m_cookiesHasBeenSet)
  {
   XmlNode cookiesNode = parentNode.CreateChildElement("Cookies");
   m_cookies.AddToNode(cookiesNode);
  }

  if(m_headersHasBeenSet)
  {
   XmlNode headersNode = parentNode.CreateChildElement("Headers");
   m_headers.AddToNode(headersNode);
  }

  if(m_queryStringCacheKeysHasBeenSet)
  {
   XmlNode queryStringCacheKeysNode = parentNode.CreateChildElement("QueryStringCacheKeys");
   m_queryStringCacheKeys.AddToNode(queryStringCacheKeysNode);
  }

}

} // namespace Model
} // namespace CloudFront
} // namespace Aws
