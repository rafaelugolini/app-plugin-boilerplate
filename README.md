[![Ensure compliance with Ledger guidelines](https://github.com/LedgerHQ/app-plugin-boilerplate/actions/workflows/guidelines_enforcer.yml/badge.svg)](https://github.com/LedgerHQ/app-plugin-boilerplate/actions/workflows/guidelines_enforcer.yml)
[![Compilation & tests](https://github.com/LedgerHQ/app-plugin-boilerplate/actions/workflows/ci-workflow.yml/badge.svg)](https://github.com/LedgerHQ/app-plugin-boilerplate/actions/workflows/ci-workflow.yml)


# app-plugin-boilerplate

This repo is a meant to be a forkable example of a plugin.

Plugins are lightweight applications that go hand-in-hand with the Ethereum
Application on a Nano (S, S plus, X) and Stax devices.

They allow users to safely interact with smart contracts by parsing the
transaction data and displaying its content in a human readable way. This is
done on a "per contract" basis, meaning a plugin is required for every DApp.

The code has been commented, and special "EDIT THIS" comments indicate where
developers are expected to adapt the code to their own needs.

It is STRONGLY recommended to follow the
[plugin guide](https://developers.ledger.com/docs/dapp/embedded-plugin/code-overview/)
in order to better understand the flow and the context for plugins.

## Ethereum SDK

Ethereum plugins need the [Ethereum SDK](https://github.com/LedgerHQ/ethereum-plugin-sdk).
You can use the `ETHEREUM_PLUGIN_SDK` variable to point to the directory where you cloned
this repository. By default, the `Makefile` expects it to be at the root directory of this
plugin repository, by the `ethereum-plugin-sdk` name.

You can see that this [CI](https://github.com/LedgerHQ/app-plugin-boilerplate/blob/develop/.github/workflows/check_sdk.yml) workflow
verifies that the SDK used is either on the latest `master` or `develop` references. This ensures
the code is compiled and tested on the latest version of the SDK.

## Smart Contracts

Smart contracts covered by the plugin shall be described here:

|  Network | Version | Smart Contract | Address |
|   ----   |   ---   |      ----      |   ---   |
| NetworkName   | VX  | ContractName  | `0x0000000000000000000000000000000000000000` |

## Functions

For the smart contracts implemented, the functions covered by the plugin shall be described here:

|Contract |    Function   | Selector  | Displayed Parameters |
|   ---   |    ---        | ---       | --- |
|ContractName  | FunctionName           | `0x00000000`| <table><tbody> <tr><td><code>type ParameterName</code></td></tr> </tbody></table> |


## Formatting

The C source code is expected to be formatted with `clang-format` 11.0.0 or higher.
