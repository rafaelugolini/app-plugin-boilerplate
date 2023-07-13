/*******************************************************************************
 *   Plugin Boilerplate
 *   (c) 2023 Ledger
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 ********************************************************************************/

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "boilerplate_plugin.h"

// List of selectors supported by this plugin.
// EDIT THIS: Adapt the variable names and change the `0x` values to match your selectors.
static const uint32_t SWAP_EXACT_ETH_FOR_TOKENS_SELECTOR = 0x7ff36ab5;
static const uint32_t BOILERPLATE_DUMMY_SELECTOR_2 = 0x13374242;

// Array of all the different boilerplate selectors. Make sure this follows the same order as the
// enum defined in `boilerplate_plugin.h`
// EDIT THIS: Use the names of the array declared above.
const uint32_t BOILERPLATE_SELECTORS[NUM_SELECTORS] = {
    SWAP_EXACT_ETH_FOR_TOKENS_SELECTOR,
    BOILERPLATE_DUMMY_SELECTOR_2,
};

// Function to dispatch calls from the ethereum app.
void dispatch_plugin_calls(int message, void *parameters) {
    switch (message) {
        case ETH_PLUGIN_INIT_CONTRACT:
            handle_init_contract(parameters);
            break;
        case ETH_PLUGIN_PROVIDE_PARAMETER:
            handle_provide_parameter(parameters);
            break;
        case ETH_PLUGIN_FINALIZE:
            handle_finalize(parameters);
            break;
        case ETH_PLUGIN_PROVIDE_INFO:
            handle_provide_token(parameters);
            break;
        case ETH_PLUGIN_QUERY_CONTRACT_ID:
            handle_query_contract_id(parameters);
            break;
        case ETH_PLUGIN_QUERY_CONTRACT_UI:
            handle_query_contract_ui(parameters);
            break;
        default:
            PRINTF("Unhandled message %d\n", message);
            break;
    }
}

// Handle call from from the ethereum app
void plugin_main(int arg0) {
    const unsigned int *args = (const unsigned int *) arg0;

    // If `ETH_PLUGIN_CHECK_PRESENCE` is set, this means the caller is just trying to
    // know whether this app exists or not. We can skip `dispatch_plugin_calls`.
    if (args[0] != ETH_PLUGIN_CHECK_PRESENCE) {
        dispatch_plugin_calls(args[0], (void *) args[1]);
    }
}
