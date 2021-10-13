# Installation Instructions

1. Get the required dependencies:
    * build-essential
    * qtbase5-dev
    * qt5-qmake
    * [PrBoom+](https://github.com/coelckers/prboom-plus) (Not technically required to build the app, but necessary for its function)

1. `cd` into the base folder (pbp-manager) if you haven't already

1. Type `make`

Bash commands:

```bash
cd pbp-manager
./scripts/ubuntu_depinstall.sh #Optional, only use on a Debian/Ubuntu based system
make
```

Assuming all went well, the compiled pbp-manager will sit in the `build` folder.

## Adding pbp-manager to your PATH

Assuming you're using a Debian/Ubuntu based distro, put: 

`PATH=$PATH:/path/to/pbp-manager` into either `~/.bashrc` or `~/.bash_aliases`, depending on your preference

then type `source ~/.bashrc`, which will update your PATH to include pbp-manager
