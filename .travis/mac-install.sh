#!/usr/bin/env bash
#
# Copyright (c) 2018 The Bitcoin Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.

export LC_ALL=C.UTF-8

brew uninstall --force --ignore-dependencies openssl autoconf fontconfig gdbm boost@1.57 glib harfbuzz jpeg libffi libtiff pixman python sqlite automake freetype gdk-pixbuf gmp icu4c libcroco libpng libtool pango pkg-config qt watch berkeley-db@4 cairo fribidi gettext graphite2 iperf libevent librsvg miniupnpc pcre protobuf readline git || exit 1
travis_retry brew update
brew cleanup -s
brew install https://raw.githubusercontent.com/Homebrew/homebrew-core/64555220bfbf4a25598523c2e4d3a232560eaad7/Formula/openssl.rb -f
travis_retry brew install autoconf fontconfig gdbm boost@1.57 glib harfbuzz jpeg libffi libtiff pixman python sqlite automake freetype gdk-pixbuf gmp icu4c libcroco libpng libtool pango pkg-config qt watch berkeley-db@4 cairo fribidi gettext graphite2 iperf libevent librsvg miniupnpc pcre protobuf readline git
brew link --overwrite --force boost@1.57