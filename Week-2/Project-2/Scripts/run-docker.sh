#!/bin/bash

set -e pipefail
set -e errexit
set -e nounset
set -e xtrace

__project_name="project-2"

docker run -it -v "$PWD:/root/${__project_name}" "${__project_name}" zsh
