﻿/*
* Copyright 2010-2017 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/

#include <aws/kinesisanalyticsv2/model/AddApplicationInputResult.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <aws/core/AmazonWebServiceResult.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/UnreferencedParam.h>

#include <utility>

using namespace Aws::KinesisAnalyticsV2::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;
using namespace Aws;

AddApplicationInputResult::AddApplicationInputResult() : 
    m_applicationVersionId(0)
{
}

AddApplicationInputResult::AddApplicationInputResult(const Aws::AmazonWebServiceResult<JsonValue>& result) : 
    m_applicationVersionId(0)
{
  *this = result;
}

AddApplicationInputResult& AddApplicationInputResult::operator =(const Aws::AmazonWebServiceResult<JsonValue>& result)
{
  JsonView jsonValue = result.GetPayload().View();
  if(jsonValue.ValueExists("ApplicationARN"))
  {
    m_applicationARN = jsonValue.GetString("ApplicationARN");

  }

  if(jsonValue.ValueExists("ApplicationVersionId"))
  {
    m_applicationVersionId = jsonValue.GetInt64("ApplicationVersionId");

  }

  if(jsonValue.ValueExists("InputDescriptions"))
  {
    Array<JsonView> inputDescriptionsJsonList = jsonValue.GetArray("InputDescriptions");
    for(unsigned inputDescriptionsIndex = 0; inputDescriptionsIndex < inputDescriptionsJsonList.GetLength(); ++inputDescriptionsIndex)
    {
      m_inputDescriptions.push_back(inputDescriptionsJsonList[inputDescriptionsIndex].AsObject());
    }
  }



  return *this;
}
