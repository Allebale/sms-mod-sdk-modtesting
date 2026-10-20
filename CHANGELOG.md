# Changelog

A release's tag is the API version (`v1.1.0` is API 1.1). Within a major version the API only grows; see [Compatibility](docs/MODDING.md#compatibility).

## 1.3.0

Versions in multiplayer: a host may take players on other builds of the game, and say which versions it needs (docs/MODDING.md, "Versions").

- `SmsNetPlayer.game_version` and `api_version`: what each player's game said when it joined (its version, the launcher's "2026.10.18.1", and the mod API it carries), so a server mod knows which commands it understands. In Lua, `sms.net.player(slot).game_version` and `.api_version` (`"1.2"`).
- `mod.ini`'s `client_api = 1.2`: what a server mod needs of the players' games; the host refuses older ones, saying why.

## 1.2.0

Multiplayer, and server mods: mods that run only on the host of a multiplayer game, a dedicated server as a rule, while the players join with the plain game (docs/MODDING.md, "Server mods").

- `api->net` (`SmsNetApi`): the game's role (host, client), whether the host is a dedicated server, the players (`SmsNetPlayer`: name, character, colour, where they are, whether they are in the stage), and on the host: commands to the players' games (`net->send`, `SmsCmd`: banner, notice, standing line, the HUD's clock, "Ready... Go!", sound, music, warp, hold, onto a Blooper, watch a player, the stage's actors shown, hidden or killed, an event script stopped, staying in the stage; each with a delay lined up across the games, and sticky for the session), a stage afresh for everyone (`net->load_stage`), and the game mode's name and state for the launcher's list.
- Events `SMS_EV_NET_PLAYER_JOINED`, `SMS_EV_NET_PLAYER_LEFT`, `SMS_EV_NET_PLAYER_ARRIVED`, `SMS_EV_NET_SESSION`.
- `mod.ini`'s `side = server`: a mod that loads only in a hosting game.
- `game->cube_count`, `game->in_cube`: the stage's trigger volumes (camera, area and the event scripts' "fast cubes"), as the game's scripts test them.

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
