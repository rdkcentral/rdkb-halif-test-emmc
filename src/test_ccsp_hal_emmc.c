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
 * @brief Tests the CcspHalEmmcGetHealthInfo function with valid input.
 *
 * This test case verifies the functionality of the CcspHalEmmcGetHealthInfo function when invoked with valid input. It checks the return status and any updated values in the eSTMGRHealthInfo structure.
 *
 * **Test Group ID:** Basic: 01
 * **Test Case ID:** 001
 * **Priority:** High
 *
 * **Pre-Conditions:** None
 * **Dependencies:** None
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
 *
 * **Test Procedure:**
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | --------- | ---------- | -------------- | ----- |
 * | 01 | Invoke CcspHalEmmcGetHealthInfo with valid input | pHealthInfo = allocated memory for eSTMGRHealthInfo structure | status = RDK_STMGR_RETURN_SUCCESS | Should be successful |
 *
 */
void test_l1_ccsp_hal_emmc_positive1_CcspHalEmmcGetHealthInfo()
{
    UT_LOG("Entering test_l1_ccsp_hal_emmc_positive1_CcspHalEmmcGetHealthInfo...");

    // Allocate memory for eSTMGRHealthInfo structure
    eSTMGRHealthInfo* pHealthInfo = malloc(sizeof(eSTMGRHealthInfo));

    // Invoke the API
    eSTMGRReturns status = CcspHalEmmcGetHealthInfo(pHealthInfo);

    // Check the return status and updated values in pHealthInfo (if any)
    UT_LOG("Invoking CcspHalEmmcGetHealthInfo with valid input...");
    UT_ASSERT_EQUAL(status, RDK_STMGR_RETURN_SUCCESS);
    // Add additional asserts to check the values in pHealthInfo

    // Free the allocated memory
    free(pHealthInfo);

    UT_LOG("Exiting test_l1_ccsp_hal_emmc_positive1_CcspHalEmmcGetHealthInfo...");
}

/**
* @brief This test case is used to verify the functionality of the CcspHalEmmcGetHealthInfo API for different device types.
*
* The purpose of this test is to ensure that the CcspHalEmmcGetHealthInfo API returns the correct status and device type for each device type passed as input.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 002
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- | -------------- | ----- |
* | 01 | Set different device types and invoke the API | i = 0, 1, 2, ..., RDK_STMGR_DEVICE_TYPE_MAX | RDK_STMGR_RETURN_SUCCESS, device type should match the input | Should pass for all device types |
*/
void test_l1_ccsp_hal_emmc_positive2_CcspHalEmmcGetHealthInfo()
{
    UT_LOG("Entering test_l1_ccsp_hal_emmc_positive2_CcspHalEmmcGetHealthInfo...");

    // Allocate memory for eSTMGRHealthInfo structure
    eSTMGRHealthInfo* pHealthInfo = malloc(sizeof(eSTMGRHealthInfo));

    // Call the API for each device type
    for (int i = 0; i <= RDK_STMGR_DEVICE_TYPE_MAX; i++)
    {
        // Set the device type
        pHealthInfo->m_deviceType = (eSTMGRDeviceType)i;

        // Invoke the API
        eSTMGRReturns status = CcspHalEmmcGetHealthInfo(pHealthInfo);

        // Check the return status and correct device type
        UT_LOG("Invoking CcspHalEmmcGetHealthInfo with device type %d...", i);
        UT_ASSERT_EQUAL(status, RDK_STMGR_RETURN_SUCCESS);
        UT_ASSERT_EQUAL(pHealthInfo->m_deviceType, i);
    }
   UT_LOG("Exiting test_l1_ccsp_hal_emmc_positive2_CcspHalEmmcGetHealthInfo...");
}

/**
* @brief This test case verifies the operational check functionality of CcspHalEmmcGetHealthInfo API.
*
* This test case checks the return status and valid value for m_isOperational attribute of the eSTMGRHealthInfo structure obtained from CcspHalEmmcGetHealthInfo API. The objective of this test is to ensure that the API returns the success status and the value of m_isOperational is either true or false.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 003
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Check the operational status | pHealthInfo = allocated memory | Success status and m_isOperational value is true or false | Should be successful |
*/

void test_l1_ccsp_hal_emmc_positive3_CcspHalEmmcGetHealthInfo()
{
    UT_LOG("Entering test_l1_ccsp_hal_emmc_positive3_CcspHalEmmcGetHealthInfo...");

    // Allocate memory for eSTMGRHealthInfo structure
    eSTMGRHealthInfo* pHealthInfo = malloc(sizeof(eSTMGRHealthInfo));

    // Invoke the API
    eSTMGRReturns status = CcspHalEmmcGetHealthInfo(pHealthInfo);

    // Check the return status and valid value for m_isOperational
    UT_LOG("Invoking CcspHalEmmcGetHealthInfo for operational check...");
    UT_ASSERT_EQUAL(status, RDK_STMGR_RETURN_SUCCESS);
    UT_ASSERT_TRUE(pHealthInfo->m_isOperational == true || pHealthInfo->m_isOperational == false);

    // Free the allocated memory
    free(pHealthInfo);

    UT_LOG("Exiting test_l1_ccsp_hal_emmc_positive3_CcspHalEmmcGetHealthInfo...");
}

/**
* @brief This test case is used to verify the HealthCheck functionality in the CcspHalEmmcGetHealthInfo API.
*
* The objective of this test case is to ensure that the CcspHalEmmcGetHealthInfo API returns the expected status and the value of m_isHealthy is either true or false.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 004
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- | -------------- | ----- |
* | 01 | Allocate memory for eSTMGRHealthInfo structure | pHealthInfo = malloc(sizeof(eSTMGRHealthInfo)) | Memory allocated successfully | Should be successful |
* | 02 | Invoke the CcspHalEmmcGetHealthInfo API | pHealthInfo | API invoked successfully | Should be successful |
* | 03 | Check the return status and valid value for m_isHealthy | status, pHealthInfo->m_isHealthy | RDK_STMGR_RETURN_SUCCESS, true or false | Should be successful |
* | 04 | Free the allocated memory | free(pHealthInfo) | Memory freed successfully | Should be successful |
*/

void test_l1_ccsp_hal_emmc_positive4_CcspHalEmmcGetHealthInfo()
{
    UT_LOG("Entering test_l1_ccsp_hal_emmc_positive4_CcspHalEmmcGetHealthInfo...");

    // Allocate memory for eSTMGRHealthInfo structure
    eSTMGRHealthInfo* pHealthInfo = malloc(sizeof(eSTMGRHealthInfo));

    // Invoke the API
    eSTMGRReturns status = CcspHalEmmcGetHealthInfo(pHealthInfo);

    // Check the return status and valid value for m_isHealthy
    UT_LOG("Invoking CcspHalEmmcGetHealthInfo for health check...");
    UT_ASSERT_EQUAL(status, RDK_STMGR_RETURN_SUCCESS);
    UT_ASSERT_TRUE(pHealthInfo->m_isHealthy == true || pHealthInfo->m_isHealthy == false);

    // Free the allocated memory
    free(pHealthInfo);

    UT_LOG("Exiting test_l1_ccsp_hal_emmc_positive4_CcspHalEmmcGetHealthInfo...");
}

/**
* @brief This test is to verify the behavior of the CcspHalEmmcGetHealthInfo API when an unexpected device type is set.
*
* The objective of this test is to ensure that the API handles unexpected device types correctly and returns the expected status.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 005
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- | -------------- | ----- |
* | 01 | Set unexpected device type (out of range) | pHealthInfo->m_deviceType = RDK_STMGR_DEVICE_TYPE_MAX + 1 | RDK_STMGR_RETURN_UNKNOWN_FAILURE | Should return RDK_STMGR_RETURN_UNKNOWN_FAILURE |
*/
void test_l1_ccsp_hal_emmc_positive5_CcspHalEmmcGetHealthInfo()
{
    UT_LOG("Entering test_l1_ccsp_hal_emmc_positive5_CcspHalEmmcGetHealthInfo...");

    // Allocate memory for eSTMGRHealthInfo structure
    eSTMGRHealthInfo* pHealthInfo = malloc(sizeof(eSTMGRHealthInfo));

    // Set unexpected device type (out of range)
    pHealthInfo->m_deviceType = (eSTMGRDeviceType)(RDK_STMGR_DEVICE_TYPE_MAX + 1);

    // Invoke the API
    eSTMGRReturns status = CcspHalEmmcGetHealthInfo(pHealthInfo);

    // Check the return status
    UT_LOG("Invoking CcspHalEmmcGetHealthInfo with unexpected device type...");
    UT_ASSERT_EQUAL(status, RDK_STMGR_RETURN_UNKNOWN_FAILURE);

    // Free the allocated memory
    free(pHealthInfo);

    UT_LOG("Exiting test_l1_ccsp_hal_emmc_positive5_CcspHalEmmcGetHealthInfo...");
}

/**
 * @brief This test case checks for null pointer check in the CcspHalEmmcGetHealthInfo API.
 *
 * The objective of this test is to verify that the CcspHalEmmcGetHealthInfo API returns the correct status when invoked with a null pointer as input argument.
 *
 * **Test Group ID:** Basic: 01
 * **Test Case ID:** 006
 * **Priority:** High
 *
 * **Pre-Conditions:** None
 * **Dependencies:** None
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
 *
 * **Test Procedure:**
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke the API with NULL pointer | pointer = NULL | RDK_STMGR_RETURN_INVALID_INPUT | Should return RDK_STMGR_RETURN_INVALID_INPUT |
 *
 */
void test_l1_ccsp_hal_emmc_negative1_CcspHalEmmcGetHealthInfo()
{
    UT_LOG("Entering test_l1_ccsp_hal_emmc_negative1_CcspHalEmmcGetHealthInfo...");

    // Invoke the API with NULL pointer
    eSTMGRReturns status = CcspHalEmmcGetHealthInfo(NULL);

    // Check the return status
    UT_LOG("Invoking CcspHalEmmcGetHealthInfo with NULL pointer...");
    UT_ASSERT_EQUAL(status, RDK_STMGR_RETURN_INVALID_INPUT);

    UT_LOG("Exiting test_l1_ccsp_hal_emmc_negative1_CcspHalEmmcGetHealthInfo...");
}

/**
 * @brief This test is to check for overflow in the m_numOfAttributes field of the eSTMGRHealthInfo structure.
 *
 * This test case checks the behavior of the CcspHalEmmcGetHealthInfo function when the m_numOfAttributes field of the eSTMGRHealthInfo structure overflows.
 *
 * **Test Group ID:** Basic: 01
 * **Test Case ID:** 007
 * **Priority:** High
 *
 * **Pre-Conditions:** None
 * **Dependencies:** None
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
 *
 * **Test Procedure:**
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :--------------: | ----------- | --------- | --------------- | ----- |
 * |       01         | Check for overflow in m_numOfAttributes field of eSTMGRHealthInfo structure | pHealthInfo = allocated memory for eSTMGRHealthInfo structure | RDK_STMGR_RETURN_SUCCESS or RDK_STMGR_RETURN_UNKNOWN_FAILURE | The test should be successful |
 */

void test_l1_ccsp_hal_emmc_negative2_CcspHalEmmcGetHealthInfo()
{
    UT_LOG("Entering test_l1_ccsp_hal_emmc_negative2_CcspHalEmmcGetHealthInfo...");

    // Allocate memory for eSTMGRHealthInfo structure
    eSTMGRHealthInfo* pHealthInfo = malloc(sizeof(eSTMGRHealthInfo));

    // Invoke the API
    eSTMGRReturns status = CcspHalEmmcGetHealthInfo(pHealthInfo);

    // Check the return status and overflow in m_numOfAttributes (if any)
    UT_LOG("Invoking CcspHalEmmcGetHealthInfo for overflow check...");
    UT_ASSERT_TRUE(status == RDK_STMGR_RETURN_SUCCESS || status == RDK_STMGR_RETURN_UNKNOWN_FAILURE);
    UT_ASSERT_FALSE(pHealthInfo->m_diagnostics.m_list.m_numOfAttributes > (UINT16_MAX - 1));
    UT_ASSERT_FALSE(pHealthInfo->m_lifetimesList.m_numOfAttributes > (UINT16_MAX - 1));
    // Add more asserts to check for overflow in other attributes

    // Free the allocated memory
    free(pHealthInfo);

    UT_LOG("Exiting test_l1_ccsp_hal_emmc_negative2_CcspHalEmmcGetHealthInfo...");
}

/**
* @brief This test checks the functionality of CcspHalEmmcGetHealthInfo when the device ID is empty or not set.
*
* The objective of this test is to verify that the function handles the case of an empty or not set device ID correctly.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 008
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Check for empty device ID | None | RDK_STMGR_RETURN_SUCCESS or RDK_STMGR_RETURN_UNKNOWN_FAILURE | Should be successful |
*/

void test_l1_ccsp_hal_emmc_negative3_CcspHalEmmcGetHealthInfo()
{
    UT_LOG("Entering test_l1_ccsp_hal_emmc_negative3_CcspHalEmmcGetHealthInfo...");

    // Allocate memory for eSTMGRHealthInfo structure
    eSTMGRHealthInfo* pHealthInfo = malloc(sizeof(eSTMGRHealthInfo));

    // Invoke the API
    eSTMGRReturns status = CcspHalEmmcGetHealthInfo(pHealthInfo);

    // Check the return status and empty or not set m_deviceID
    UT_LOG("Invoking CcspHalEmmcGetHealthInfo for empty device ID check...");
    UT_ASSERT_TRUE(status == RDK_STMGR_RETURN_SUCCESS || status == RDK_STMGR_RETURN_UNKNOWN_FAILURE);
    // Add assert to check for empty or not set m_deviceID

    // Free the allocated memory
    free(pHealthInfo);

    UT_LOG("Exiting test_l1_ccsp_hal_emmc_negative3_CcspHalEmmcGetHealthInfo...");
}

/**
* @brief Test case to check the behavior of CcspHalEmmcGetHealthInfo when the eSTMGRHealthInfo structure is uninitialized.
*
* This test case checks if the API CcspHalEmmcGetHealthInfo returns RDK_STMGR_RETURN_INIT_FAILURE when the eSTMGRHealthInfo structure is not initialized.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 009
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- | -------------- | ----- |
* | 01 | Invoking CcspHalEmmcGetHealthInfo with uninitialized structure |  | RDK_STMGR_RETURN_INIT_FAILURE | Should return RDK_STMGR_RETURN_INIT_FAILURE |
*/
void test_l1_ccsp_hal_emmc_negative4_CcspHalEmmcGetHealthInfo()
{
    UT_LOG("Entering test_l1_ccsp_hal_emmc_negative4_CcspHalEmmcGetHealthInfo...");

    // Declare eSTMGRHealthInfo structure without initializing it

    // Invoke the API
    eSTMGRHealthInfo* pHealthInfo = NULL;
    eSTMGRReturns status = CcspHalEmmcGetHealthInfo(pHealthInfo);

    // Check the return status and initialized fields in pHealthInfo (if any)
    UT_LOG("Invoking CcspHalEmmcGetHealthInfo with uninitialized structure...");
    UT_ASSERT_EQUAL(status, RDK_STMGR_RETURN_INIT_FAILURE);
    // Add additional asserts to check the initialized fields

    UT_LOG("Exiting test_l1_ccsp_hal_emmc_negative4_CcspHalEmmcGetHealthInfo...");
}

/**
 * @brief Test case to verify the functionality of CcspHalEmmcGetDeviceInfo API.
 *
 * This test case checks the CcspHalEmmcGetDeviceInfo function with valid parameters.
 *
 * **Test Group ID:** Basic: 01
 * **Test Case ID:** 010
 * **Priority:** High
 *
 * **Pre-Conditions:** None
 * **Dependencies:** None
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
 *
 * **Test Procedure:**
 * - | Variation / Step | Description | Test Data | Expected Result | Notes |
 * - | :----: | --------- | ---------- |-------------- | ----- |
 * - | 01 | Invoking CcspHalEmmcGetDeviceInfo with valid parameters (pDeviceInfo = non-NULL) | pDeviceInfo = non-NULL | RDK_STMGR_RETURN_SUCCESS | Should be successful |
 */
void test_l1_ccsp_hal_emmc_positive1_CcspHalEmmcGetDeviceInfo(void)
{
    UT_LOG("Entering test_l1_ccsp_hal_emmc_positive1_CcspHalEmmcGetDeviceInfo...");

    // Allocate memory for pDeviceInfo
    eSTMGRDeviceInfo* pDeviceInfo = malloc(sizeof(eSTMGRDeviceInfo));

    // Test the API with valid parameters
    UT_LOG("Invoking CcspHalEmmcGetDeviceInfo with valid parameters (pDeviceInfo = non-NULL)");
    eSTMGRReturns result = CcspHalEmmcGetDeviceInfo(pDeviceInfo);

    // Check the return value
    UT_ASSERT_EQUAL(result, RDK_STMGR_RETURN_SUCCESS);
    UT_LOG("Returned: RDK_STMGR_RETURN_SUCCESS");

    // Free allocated memory
    free(pDeviceInfo);

    UT_LOG("Exiting test_l1_ccsp_hal_emmc_positive1_CcspHalEmmcGetDeviceInfo...");
}

/**
 * @brief Test for checking the device ID in the eSTMGRDeviceInfo structure
 *
 * This test verifies the correctness of the device ID stored in the eSTMGRDeviceInfo structure by calling the CcspHalEmmcGetDeviceInfo API.
 *
 * **Test Group ID:** Basic: 01
 * **Test Case ID:** 011
 * **Priority:** High
 *
 * **Pre-Conditions:** None
 * **Dependencies:** None
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
 *
 * **Test Procedure:**
 *
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | ---------- | --------- | --------------- | ----- |
 * | 01 | Test CcspHalEmmcGetDeviceInfo API | pDeviceInfo = allocated | Success | Should be successful |
 */
void test_l1_ccsp_hal_emmc_positive2_CcspHalEmmcGetDeviceInfo(void)
{
    UT_LOG("Entering test_l1_ccsp_hal_emmc_positive2_CcspHalEmmcGetDeviceInfo...");

    // Allocate memory for pDeviceInfo
    eSTMGRDeviceInfo* pDeviceInfo = malloc(sizeof(eSTMGRDeviceInfo));

    // Test the API and check m_deviceID
    UT_LOG("Invoking CcspHalEmmcGetDeviceInfo to check m_deviceID");
   // eSTMGRReturns result = CcspHalEmmcGetDeviceInfo(pDeviceInfo);

    // Validate m_deviceID
    UT_ASSERT_PTR_NOT_NULL(pDeviceInfo->m_deviceID);
    UT_LOG("m_deviceID: %s", pDeviceInfo->m_deviceID);

    // Free allocated memory
    free(pDeviceInfo);

    UT_LOG("Exiting test_l1_ccsp_hal_emmc_positive2_CcspHalEmmcGetDeviceInfo...");
}

/**
* @brief Function to test the CcspHalEmmcGetDeviceInfo API to check the device type.
*
* This test case is used to validate if the CcspHalEmmcGetDeviceInfo API correctly retrieves the device type and if it falls within the expected range of device types.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 012
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoking CcspHalEmmcGetDeviceInfo to check m_type | pDeviceInfo = allocated memory | API returns success (eSTMGRReturns = success) | m_type is within the expected range of device types |
*/
void test_l1_ccsp_hal_emmc_positive3_CcspHalEmmcGetDeviceInfo(void)
{
    UT_LOG("Entering test_l1_ccsp_hal_emmc_positive3_CcspHalEmmcGetDeviceInfo...");

    // Allocate memory for pDeviceInfo
    eSTMGRDeviceInfo* pDeviceInfo = malloc(sizeof(eSTMGRDeviceInfo));

    // Test the API and check m_type
    UT_LOG("Invoking CcspHalEmmcGetDeviceInfo to check m_type");
   // eSTMGRReturns result = CcspHalEmmcGetDeviceInfo(pDeviceInfo);

    // Validate m_type
    UT_ASSERT_TRUE(pDeviceInfo->m_type >= RDK_STMGR_DEVICE_TYPE_HDD && pDeviceInfo->m_type <= RDK_STMGR_DEVICE_TYPE_MAX);
    UT_LOG("m_type: %d", pDeviceInfo->m_type);

    // Free allocated memory
    free(pDeviceInfo);

    UT_LOG("Exiting test_l1_ccsp_hal_emmc_positive3_CcspHalEmmcGetDeviceInfo...");
}

/**
* @brief This function tests the negative scenario of the CcspHalEmmcGetDeviceInfo API.
*
* The objective of this test is to validate the behavior of the CcspHalEmmcGetDeviceInfo API
* when it is invoked with a NULL parameter as input.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 013
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke CcspHalEmmcGetDeviceInfo with NULL parameter | deviceInfo = NULL | RDK_STMGR_RETURN_INVALID_INPUT | Should return RDK_STMGR_RETURN_INVALID_INPUT |
*/
void test_l1_ccsp_hal_emmc_negative1_CcspHalEmmcGetDeviceInfo(void)
{
    UT_LOG("Entering test_l1_ccsp_hal_emmc_negative1_CcspHalEmmcGetDeviceInfo...");

    // Test the API with NULL parameter
    UT_LOG("Invoking CcspHalEmmcGetDeviceInfo with NULL parameter");
    eSTMGRReturns result = CcspHalEmmcGetDeviceInfo(NULL);

    // Check the return value
    UT_ASSERT_EQUAL(result, RDK_STMGR_RETURN_INVALID_INPUT);
    UT_LOG("Returned: RDK_STMGR_RETURN_INVALID_INPUT");

    UT_LOG("Exiting test_l1_ccsp_hal_emmc_negative1_CcspHalEmmcGetDeviceInfo...");
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
    UT_add_test(pSuite, "l1_ccsp_hal_emmc_positive1_CcspHalEmmcGetHealthInfo", test_l1_ccsp_hal_emmc_positive1_CcspHalEmmcGetHealthInfo);
    UT_add_test(pSuite, "l1_ccsp_hal_emmc_positive2_CcspHalEmmcGetHealthInfo", test_l1_ccsp_hal_emmc_positive2_CcspHalEmmcGetHealthInfo);
    UT_add_test(pSuite, "l1_ccsp_hal_emmc_positive3_CcspHalEmmcGetHealthInfo", test_l1_ccsp_hal_emmc_positive3_CcspHalEmmcGetHealthInfo);
    UT_add_test(pSuite, "l1_ccsp_hal_emmc_positive4_CcspHalEmmcGetHealthInfo", test_l1_ccsp_hal_emmc_positive4_CcspHalEmmcGetHealthInfo);
    UT_add_test(pSuite, "l1_ccsp_hal_emmc_positive5_CcspHalEmmcGetHealthInfo", test_l1_ccsp_hal_emmc_positive5_CcspHalEmmcGetHealthInfo);
    UT_add_test(pSuite, "l1_ccsp_hal_emmc_negative1_CcspHalEmmcGetHealthInfo", test_l1_ccsp_hal_emmc_negative1_CcspHalEmmcGetHealthInfo);
    UT_add_test(pSuite, "l1_ccsp_hal_emmc_negative2_CcspHalEmmcGetHealthInfo", test_l1_ccsp_hal_emmc_negative2_CcspHalEmmcGetHealthInfo);
    UT_add_test(pSuite, "l1_ccsp_hal_emmc_negative3_CcspHalEmmcGetHealthInfo", test_l1_ccsp_hal_emmc_negative3_CcspHalEmmcGetHealthInfo);
    UT_add_test(pSuite, "l1_ccsp_hal_emmc_negative4_CcspHalEmmcGetHealthInfo", test_l1_ccsp_hal_emmc_negative4_CcspHalEmmcGetHealthInfo);
    UT_add_test(pSuite, "l1_ccsp_hal_emmc_positive1_CcspHalEmmcGetDeviceInfo", test_l1_ccsp_hal_emmc_positive1_CcspHalEmmcGetDeviceInfo);
    UT_add_test(pSuite, "l1_ccsp_hal_emmc_positive2_CcspHalEmmcGetDeviceInfo", test_l1_ccsp_hal_emmc_positive2_CcspHalEmmcGetDeviceInfo);
    UT_add_test(pSuite, "l1_ccsp_hal_emmc_positive3_CcspHalEmmcGetDeviceInfo", test_l1_ccsp_hal_emmc_positive3_CcspHalEmmcGetDeviceInfo);
    UT_add_test(pSuite, "l1_ccsp_hal_emmc_negative1_CcspHalEmmcGetDeviceInfo", test_l1_ccsp_hal_emmc_negative1_CcspHalEmmcGetDeviceInfo);
    
    return 0;
}

