# DSA Problem Solving

Run commands:

```bash
g++ -std=c++17 "filename.cpp" -o filename && ./filename
```

Quick compile all `.cpp` files (optional):

```bash
for f in *.cpp; do out="${f%%.*}"; g++ -std=c++17 "$f" -o "$out" && echo "Built $out"; done
```
