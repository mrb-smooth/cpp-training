#!/bin/bash

# Creator:    Malik R Booker
# Created:    December 1, 2021
# Updated:    December 5, 2021

# Don't execute if previously initialized
if [ -f "/root/.initialized" ];
then
    exit
else
    echo "installing deps"
fi

set -o pipefail
set -o errexit
set -o nounset
set -o xtrace

#################
### Functions ###
#################

function cpp-training {
    git clone https://github.com/mrb-smooth/cpp-training ~/cpp-training
}

####################
### Begin Script ###
####################

# Handle command line
for i in "$@"; do
    case $i in
        --all)
            cpp-training
            break
            ;;
        -c|--config)
            #editor-tools
            shift # past argument with no value
            ;;
        -x|--extra)
            #extra-languages
            shift # past argument with no value
            ;;
        *)
            # unknown option
            ;;
    esac
done

# Set .initialized to prevent reinitialization
touch /root/.initialized
