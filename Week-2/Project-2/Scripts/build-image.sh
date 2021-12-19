#!/bin/bash

set -e pipefail
set -e errexit
set -e nounset
set -e xtrace

__project_name="project-2"

docker build -t ${__project_name} -f Dockerfile .
