#!/bin/bash

sudo gpio export 20 out
sudo gpio export 24 in
sudo gpio export 25 in
sudo gpio export 23 in
sudo gpio export 22 out
sudo gpio export 8 in
sudo gpio export 9 in
sudo gpio export 11 in
sudo gpio export 10 in

sudo ./build/ERT2020GS