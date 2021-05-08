# cos8o give me hyperdash
---

## Installation
1. Download this github files and unzip it
2. Download [Android NDK 16b](https://developer.android.com/ndk/downloads/older_releases)

## Compiling
```sh
./build.bat
```

## Loading the libbt1p0.so
1. Open GeometryDash/smali/com/robtopx/geometryjump/geometryjump.smali
2. Add this to the first static constructor method
```
  .line 70
  const-string v0, "bt1p0"
  invoke-static {v0}, Ljava/lang/System;->loadLibrary(Ljava/lang/String;)V
```

---
## Special thanks
- FlairyDash and кафiф

---
### Join [Galaxium](https://discord.gg/ZV2zDu6JUX)
