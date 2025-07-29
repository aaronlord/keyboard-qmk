# Keyboard Firmware

I don't really want QMK's full repo, so here is just _my_ config.

Just clone QMK, clone this repo into `qmk_firmware/keyboards/my_dactyl`, then build with:

```
./util/docker_cmd.sh qmk compile -kb my_dactyl -km default
```
