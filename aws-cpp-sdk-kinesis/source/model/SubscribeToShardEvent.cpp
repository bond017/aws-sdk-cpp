﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/kinesis/model/SubscribeToShardEvent.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::Utils::Json;
using namespace Aws::Utils;

namespace Aws
{
namespace Kinesis
{
namespace Model
{

SubscribeToShardEvent::SubscribeToShardEvent() : 
    m_recordsHasBeenSet(false),
    m_continuationSequenceNumberHasBeenSet(false),
    m_millisBehindLatest(0),
    m_millisBehindLatestHasBeenSet(false)
{
}

SubscribeToShardEvent::SubscribeToShardEvent(JsonView jsonValue) : 
    m_recordsHasBeenSet(false),
    m_continuationSequenceNumberHasBeenSet(false),
    m_millisBehindLatest(0),
    m_millisBehindLatestHasBeenSet(false)
{
  *this = jsonValue;
}

SubscribeToShardEvent& SubscribeToShardEvent::operator =(JsonView jsonValue)
{
  if(jsonValue.ValueExists("Records"))
  {
    Array<JsonView> recordsJsonList = jsonValue.GetArray("Records");
    for(unsigned recordsIndex = 0; recordsIndex < recordsJsonList.GetLength(); ++recordsIndex)
    {
      m_records.push_back(recordsJsonList[recordsIndex].AsObject());
    }
    m_recordsHasBeenSet = true;
  }

  if(jsonValue.ValueExists("ContinuationSequenceNumber"))
  {
    m_continuationSequenceNumber = jsonValue.GetString("ContinuationSequenceNumber");

    m_continuationSequenceNumberHasBeenSet = true;
  }

  if(jsonValue.ValueExists("MillisBehindLatest"))
  {
    m_millisBehindLatest = jsonValue.GetInt64("MillisBehindLatest");

    m_millisBehindLatestHasBeenSet = true;
  }

  return *this;
}

JsonValue SubscribeToShardEvent::Jsonize() const
{
  JsonValue payload;

  if(m_recordsHasBeenSet)
  {
   Array<JsonValue> recordsJsonList(m_records.size());
   for(unsigned recordsIndex = 0; recordsIndex < recordsJsonList.GetLength(); ++recordsIndex)
   {
     recordsJsonList[recordsIndex].AsObject(m_records[recordsIndex].Jsonize());
   }
   payload.WithArray("Records", std::move(recordsJsonList));

  }

  if(m_continuationSequenceNumberHasBeenSet)
  {
   payload.WithString("ContinuationSequenceNumber", m_continuationSequenceNumber);

  }

  if(m_millisBehindLatestHasBeenSet)
  {
   payload.WithInt64("MillisBehindLatest", m_millisBehindLatest);

  }

  return payload;
}

} // namespace Model
} // namespace Kinesis
} // namespace Aws
