/*
* If not stated otherwise in this file or this component's LICENSE file the
* following copyright and licenses apply:*
* Copyright 2016 RDK Management
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

/**
* @file test_ccsp_hal_emmc.c
* @page ccsp_hal_emmc Level 1 Tests
*
* ## Module's Role
* This module includes Level 1 functional tests (success and failure scenarios).
* This is to ensure that the ccsp_hal_emmc APIs meet the requirements across all vendors.
*
* **Pre-Conditions:**  None@n
* **Dependencies:** None@n
*
* Ref to API Definition specification documentation : [halSpec.md](../../../docs/halSpec.md)
*/

#include <ut.h>
#include <stdlib.h>
#include <stdint.h>
#include <ut_log.h>
#include "ccsp_hal_emmc.h"

/**
* @brief This test checks the functionality of the CcspHalEmmcGetHealthInfo API
*
* This test is designed to validate the positive scenario of the CcspHalEmmcGetHealthInfo API. It checks if the API is able to successfully retrieve the health information of the eMMC.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 001@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke the CcspHalEmmcGetHealthInfo API with a valid eSTMGRHealthInfo pointer | eSTMGRHealthInfo pointer = &healthInfo | The return value should be RDK_STMGR_RETURN_SUCCESS | The API should successfully retrieve the health information of the eMMC |
*/
void test_l1_ccsp_hal_emmc_positive1_CcspHalEmmcGetHealthInfo(void)
{
    UT_LOG_INFO("Entering %s\n", __FUNCTION__);

    eSTMGRHealthInfo healthInfo;

    UT_LOG_DEBUG("Invoking CcspHalEmmcGetHealthInfo with valid eSTMGRHealthInfo pointer");
    eSTMGRReturns ret = CcspHalEmmcGetHealthInfo(&healthInfo);
    UT_ASSERT_EQUAL(ret, RDK_STMGR_RETURN_SUCCESS);

    UT_LOG_INFO("Exiting %s\n", __FUNCTION__);
}

/**
* @brief This test is designed to check the behavior of the CcspHalEmmcGetHealthInfo function when passed a NULL pointer.
*
* In this test, we are testing the robustness of the CcspHalEmmcGetHealthInfo function. We want to ensure that the function can handle being passed a NULL pointer without crashing or behaving unexpectedly.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 002@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke CcspHalEmmcGetHealthInfo with NULL pointer | NULL | The function should return RDK_STMGR_RETURN_INVALID_INPUT | The function should handle NULL input gracefully |
*/
void test_l1_ccsp_hal_emmc_negative1_CcspHalEmmcGetHealthInfo(void)
{
    UT_LOG_INFO("Entering %s\n", __FUNCTION__);

    UT_LOG_DEBUG("Invoking CcspHalEmmcGetHealthInfo with NULL pointer");
    eSTMGRReturns ret = CcspHalEmmcGetHealthInfo(NULL);
    UT_ASSERT_EQUAL(ret, RDK_STMGR_RETURN_INVALID_INPUT);

    UT_LOG_INFO("Exiting %s\n", __FUNCTION__);
}   

/**
* @brief This test case is designed to test the positive scenario of the CcspHalEmmcGetHealthInfo API
*
* In this test case, we are testing if the CcspHalEmmcGetHealthInfo API is able to successfully retrieve the health information of the eMMC and populate the m_deviceID correctly.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 003@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke the CcspHalEmmcGetHealthInfo API with a valid eSTMGRHealthInfo pointer | eSTMGRHealthInfo pointer = &healthInfo | The return value should be RDK_STMGR_RETURN_SUCCESS and the m_deviceID should not be an empty string | The test should be successful |
*/
void test_l1_ccsp_hal_emmc_positive2_CcspHalEmmcGetHealthInfo(void)
{
    UT_LOG_INFO("Entering %s\n", __FUNCTION__);

    eSTMGRHealthInfo healthInfo;

    UT_LOG_DEBUG("Invoking CcspHalEmmcGetHealthInfo with valid eSTMGRHealthInfo pointer and checking if the m_deviceID is populated correctly");
    eSTMGRReturns ret = CcspHalEmmcGetHealthInfo(&healthInfo);
    UT_ASSERT_EQUAL(ret, RDK_STMGR_RETURN_SUCCESS);
    UT_ASSERT_STRING_NOT_EQUAL(healthInfo.m_deviceID, "");

    UT_LOG_INFO("Exiting %s\n", __FUNCTION__);
}

/**
* @brief This test is designed to verify the positive scenario of the CcspHalEmmcGetDeviceInfo API
*
* In this test, the CcspHalEmmcGetDeviceInfo API is invoked with a valid eSTMGRDeviceInfo pointer and the return value is checked against the expected return value to validate the functionality of the API.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 004@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke the CcspHalEmmcGetDeviceInfo API with a valid eSTMGRDeviceInfo pointer | eSTMGRDeviceInfo pointer = &deviceInfo | The return value should be RDK_STMGR_RETURN_SUCCESS | The test should pass |
*/
void test_l1_ccsp_hal_emmc_positive1_CcspHalEmmcGetDeviceInfo(void)
{
    UT_LOG_INFO("Entering %s\n", __FUNCTION__);

    eSTMGRDeviceInfo deviceInfo;

    UT_LOG_DEBUG("Invoking CcspHalEmmcGetDeviceInfo with valid eSTMGRDeviceInfo pointer");
    eSTMGRReturns ret = CcspHalEmmcGetDeviceInfo(&deviceInfo);
    UT_ASSERT_EQUAL(ret, RDK_STMGR_RETURN_SUCCESS);

    UT_LOG_INFO("Exiting %s\n", __FUNCTION__);
}

/**
* @brief This test is designed to check the behavior of the CcspHalEmmcGetDeviceInfo API when invoked with NULL pointer.
*
* In this test, we are testing the robustness of the CcspHalEmmcGetDeviceInfo API. We are trying to invoke the API with NULL pointer to see if it can handle such erroneous inputs gracefully.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 005@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke CcspHalEmmcGetDeviceInfo API with NULL pointer | NULL | The API should return RDK_STMGR_RETURN_INVALID_INPUT | The API should handle erroneous inputs gracefully |
*/
void test_l1_ccsp_hal_emmc_negative1_CcspHalEmmcGetDeviceInfo(void)
{
    UT_LOG_INFO("Entering %s\n", __FUNCTION__);

    UT_LOG_DEBUG("Invoking CcspHalEmmcGetDeviceInfo with NULL pointer");
    eSTMGRReturns ret = CcspHalEmmcGetDeviceInfo(NULL);
    UT_ASSERT_EQUAL(ret, RDK_STMGR_RETURN_INVALID_INPUT);

    UT_LOG_INFO("Exiting %s\n", __FUNCTION__);
}

static UT_test_suite_t * pSuite = NULL;

/**
 * @brief Register the main tests for this module
 *
 * @return int - 0 on success, otherwise failure
 */
int test_emmc_hal_l1_register(void)
{
    // Create the test suite
    pSuite = UT_add_suite("[L1 ccsp_hal_emmc]", NULL, NULL);
    if (pSuite == NULL)
    {
        return -1;
    }
    // List of test function names and strings
    UT_add_test( pSuite, "l1_ccsp_hal_emmc_positive1_CcspHalEmmcGetHealthInfo", test_l1_ccsp_hal_emmc_positive1_CcspHalEmmcGetHealthInfo);
    UT_add_test( pSuite, "l1_ccsp_hal_emmc_positive2_CcspHalEmmcGetHealthInfo", test_l1_ccsp_hal_emmc_positive2_CcspHalEmmcGetHealthInfo);
    UT_add_test( pSuite, "l1_ccsp_hal_emmc_negative1_CcspHalEmmcGetHealthInfo", test_l1_ccsp_hal_emmc_negative1_CcspHalEmmcGetHealthInfo);
    UT_add_test( pSuite, "l1_ccsp_hal_emmc_positive1_CcspHalEmmcGetDeviceInfo", test_l1_ccsp_hal_emmc_positive1_CcspHalEmmcGetDeviceInfo);
    UT_add_test( pSuite, "l1_ccsp_hal_emmc_negative1_CcspHalEmmcGetDeviceInfo", test_l1_ccsp_hal_emmc_negative1_CcspHalEmmcGetDeviceInfo);
    return 0;
}

