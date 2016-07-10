#!/bin/bash
#
# Simple installer for time_daemon

install() {
        echo -n "installing time_daemon"
        cp time_daemon /bin/
}

uninstall() {
        echo -n "Uninstalling time_daemon"
        rm -f /bin/time_daemon
        rm -f /var/log/time.log
}

case "$1" in
    install)
        install
        ;;
    uninstall)
        uninstall
        ;;
    *)
        echo "Usage: time_daemon {install|uninstall}"
        exit 1
        ;;
esac
exit $?
