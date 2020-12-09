#!/usr/bin/python3
"""[Lockboxes]"""

def canUnlockAll(boxes):
    """Unlock check"""
    if len(boxes) == 1:
        return True
    allKeys = []

    for box in boxes:
        for key in box:
            allKeys.append(key)

    for key in range(len(boxes)):
        if key in boxes[key]:
            if allKeys.count(key) == 1:
                return False
    return True
