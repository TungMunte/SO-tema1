#!/bin/bash

# SPDX-License-Identifier: BSD-3-Clause

source graded_test.inc.sh

exec_file=./memory/malloc

test_malloc()
{
    if test ! -f "$exec_file"; then
        echo "No such file $exec_file" 1>&2
        exit 1
    fi

    nm "$exec_file" > /dev/null 2>&1
    if test $? -ne 0; then
        echo "No symbols in file" 1>&2
        exit 1
    fi

    nm "$exec_file" | grep ' malloc$' > /dev/null
    if test $? -ne 0; then
        echo "No malloc symbol" 1>&2
        exit 1
    fi

    nm "$exec_file" | grep ' mmap$' > /dev/null
    if test $? -ne 0; then
        echo "No mmap symbol" 1>&2
        exit 1
    fi

    timeout -k 1 2 strace "$exec_file" 2>&1 > /dev/null | grep mmap > /dev/null
    if test $? -ne 0; then
        echo "No mmap syscall" 1>&2
        exit 1
    fi

    "$exec_file" &
    PID=$!
    mem1=$(ps -o vsz --noheader --pid $PID)
    sleep 2
    mem2=$(ps -o vsz --noheader --pid $PID)
    kill $!
    kill -9 $!

    diff=$((mem2-mem1))
    if test "$diff" -lt 1024; then
        exit 1
    fi

    exit 0
}

run_test test_malloc 10
