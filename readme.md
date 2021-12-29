# Natsume’s customization of ZSA’s fork of QMK-framework

## How to build
Run in a “QMK MSYS” shell:
make moonlander:mine

## Features
- Defined layers:
  - 3 different layouts: Mine (de), JISX6004 (ja), QWERTZ (de).
  - 2 layers with symbols for programming and writing.
  - Edit layer with cursor navigation, copy/cut/paste, etc.
  - NumPad layer and mouse navigation
  - One layer dedicated to media and keyboard control.
- Keys for switching layouts (default layers) and language settings (de, ja) in Windows with one tap.
- Chainable Multi-OSLs that do not require TAPPING_TERM to pass until same key can be used for another OSL action.
- NumLock LED and NumLock key that is animated when NumLock is not active.
- Single key rgb animations: breathing, rainbow, hue gradient, color switch.
- Enable custom tapping terms for certain keys.
- Enable sticky shift key to further reduce need for key combos.
- Heatmap reflecting occurances of key presses. Also suports dumping its data to allow simple statistical evaluations.
- Ctrl dance to provide compact <key>/CTRL+<key> combos, which do not cause lags (TAPPING_TERM) during typing.

## Architectural Measures
- Modularize keymap.
- Custom actions infrastructure similar to actions infrastructure provided by core code.
- Extract common layer that serves as a base for all layout/default layers to make intended commonalities more explicit.
- Use unicode map to generate symbols. Provides a more reliable and maintainable experience than ordinary unicode macros.
