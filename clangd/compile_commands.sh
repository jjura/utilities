#!/bin/bash

while [ ! -z "${*}" ]
do
    case "${1}" in
        "--compiler" )
            compiler="${2}"
            shift 2 ;;

        "--directory" )
            directory="${2}"
            shift 2 ;;
    esac
done

compiler="${compiler:-cc}"
directory="${directory:-${PWD}}"

make                                           \
    --always-make                              \
    --directory "${directory}"                 \
    --dry-run                                  \
    | grep --extended-regexp -- "^${compiler}" \
    | grep --extended-regexp -- " -c "         \
    | jq --raw-input --null-input '
        [ inputs 
          | select(length > 0) 
          | {
              directory: "'"${directory}"'", 
              command: ., 
              file: match("\\b\\S+\\.[c|cpp|cc]+\\b").string
            }
        ]'
