def dictToFeml(src):
    rc = ""
    for k, v in src:
        rc += f"{k}={v}\n"
    return rc
