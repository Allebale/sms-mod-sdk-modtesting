# Changelog

A release's tag is the API version (`v1.1.0` is API 1.1). Within a major version the API only grows; see [Compatibility](docs/MODDING.md#compatibility).

## 1.1.1

- The lua mod's Linux libraries load on glibc 2.35 and newer (Ubuntu 22.04, Debian 12, SteamOS); 1.1.0's needed 2.38. CI builds Linux mods on Ubuntu 22.04, and the templates' workflows do too.

## 1.1.0

The SDK as its own repository, split from the port's `sdk/` folder with its history.

- `core->mod_info(mod, key)`: a value from a mod's `mod.ini`.
- `core->host_runtime(host, runtime, start, stop, user)`: a native mod runs script mods (`runtime = <name>` in their `mod.ini`). The lua mod uses it.
- The **lua** mod (`lua/`), released as an optional mod with a library for every platform.
- `SMS_API_HAS` is plain C and C++ (it used `__typeof__`, which MSVC's C compiler lacks).
- `SmsMod.cmake` works as a FetchContent dependency (the target `sms::mod_sdk`, `-m32`/`-m64` per target), names macOS libraries `.dylib` as the game looks for them, and links MSVC's C runtime statically.
- The examples moved to [sms-mod-templates](https://github.com/chasem-dev/sms-mod-templates).

## 1.0.0

The first API: events with priorities, cancelling and consuming; the `core`, `game`, `player`, `camera`, `draw`, `input`, `config`, `audio` and `native` tables; HUD slots; the Mods menu's options; key bindings; services and custom events between mods.
