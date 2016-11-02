#!/bin/bash
set -e

cd /tmp
git clone git@github.com:smibarber/libSOIL.git
make -C /tmp/libSOIL/
sudo make -C /tmp/libSOIL/ install
rm -r /tmp/libSOIL
