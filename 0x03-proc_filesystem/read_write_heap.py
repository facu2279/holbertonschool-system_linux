#!/usr/bin/python3
<<<<<<< HEAD
"""
This file is used to modify bytes in a string for a running process in Linux
by modifying the /proc/{id}/mem file

Written by: David Orejuela
"""


import sys


def represents_int(pid):
    """

    Args:
        pid: number to be used as pid

    Returns: True if can be converted to int, False otherwise

    """
    try:
        int(pid)
        return True
    except ValueError:
        return False


def isascii_encodable(string):
    """

    Args:
        string: String to check if can be ASCII encoded

    Returns: True if can be ASCII encoded, false otherwise

    """
    try:
        string.encode("ASCII")
        return True
    except UnicodeEncodeError:
        return False


def parse_inputs():
    """
    This function checks that every input is the one that program expected

    Returns:
        pid: int with the process id
        search_bytes: ASCII encoded search bytes
        replace_bytes: ASCII encoded replace bytes
    """
    if (len(sys.argv) != 4):
        print("Usage: ./read_write_heap [pid]"
              " [search_string] [replace_string]")
        exit(1)
    if not represents_int(sys.argv[1]):
        print("{} must be an integer".format(sys.argv[1]))
        exit(1)
    [(print("{} must be ascii".format(x)), exit(1)) for x in sys.argv[2:]
        if not isascii_encodable(x)]
    return (int(sys.argv[1]), sys.argv[2].encode("ASCII"),
            sys.argv[3].encode("ASCII"))


def get_heap_positions(pid):
    """

    Args:
        pid: number of the desired process

    Returns:
        range of the heap positions or corresponding error otherwise

    """
    try:
        with open("/proc/{}/maps".format(pid)) as map_file:
            for line in map_file:
                if line.endswith("[heap]\n"):
                    return (int(x, 16) for x in line.split()[0].split("-"))
            print("Heap memory wasn't found")
            exit(1)
    except Exception as err:
        print("Error in maps: {}".format(err))
        exit(1)


def write_inheap(pid, search_bytes, replace_bytes, heap_start, heap_end):
    """

    Args:
        pid: number of the process
        search_bytes: bytes to search for
        replace_bytes: bytes to replace for
        heap_start: initial heap number
        heap_end: ending heap number

    """
    try:
        with open("/proc/{}/mem".format(pid), "r+b") as mem_file:
            mem_file.seek(heap_start)
            print("Heap size: {}".format(heap_end - heap_start))
            data = mem_file.read(heap_end - heap_start)
            data_pos = data.find(search_bytes)
            if data_pos == -1:
                print("The string {} is not in the heap".format(search_bytes))
                exit(1)
            if (heap_start + data_pos + len(replace_bytes)) + 1 > heap_end:
                print("The replace {} overlaps the heap".format(replace_bytes))
                exit(1)
            print("Found in byte: 0x{:02x}".format(heap_start + data_pos))
            mem_file.seek(heap_start + data_pos)
            mem_file.write(replace_bytes + b'\x00')
    except Exception as err:
        print("Error in mem: {}".format(err))
        exit(1)


def main():
    """
    Logic to get the user input, obtain the heap positions and overlaps
    the search string with the replacement string
    (Sudo permissions are needed)
    """
    pid, search_bytes, replace_bytes = parse_inputs()
    print("{} for {} in PID {}".format(search_bytes, replace_bytes, pid))
    heap_start, heap_end = get_heap_positions(pid)
    print("Heap bytes: 0x{:02x} - 0x{:02x}".format(heap_start, heap_end))
    write_inheap(pid, search_bytes, replace_bytes, heap_start, heap_end)

if __name__ == "__main__":
    main()
=======
""" Made by Facundo Diaz for Holberton School 2021"""
from sys import argv


def loop():
    """ aa """
    try:
        salida = 1
        (pid, string, new) = cambiar_formato()
        modificar_file(pid, string, new)
        salida = 0

    except Exception as e:
        print(e)
    finally:
        exit(salida)


def modificar_file(pid, string, new):
    """ aa """
    mapa = "/proc/{:d}/maps".format(pid)
    memoria = "/proc/{:d}/mem".format(pid)
    heap = "[heap]"
    dict = {"start": None, "end": None, "perms": None}

    with open(mapa, "r") as mapa, open(memoria, "rb+") as memoria:
        for line in mapa:
            if heap in line:
                print("[*] Found heap")
                tmp = line.split(" ")
                direccion = tmp[0].split("-")
                dict["start"] = int(direccion[0], 16)
                dict["end"] = int(direccion[1], 16)
                dict["perms"] = tmp[1]
                break

        if dict["perms"][:2] != "rw":
            raise PermissionError

        memoria.seek(dict["start"])
        content = memoria.read(dict["end"] - dict["start"])
        index = content.index(bytes(string, "ASCII"))
        print(content + "\n[*] Found string\n[*] Replacing string")
        memoria.seek(dict["start"] + index)
        memoria.write(bytes(new + "\0", "ASCII"))


def cambiar_formato():
    """ aa """
    pid = int(argv[1])
    string = argv[2]
    sig = argv[3]
    if len(sig) > len(string):
        raise IndexError

    return pid, string, sig


if __name__ == '__main__':
    loop()
>>>>>>> 0af8a62a7d07ea453c9a1197e01cc0b1bf9ac49e
