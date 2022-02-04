# oss-fuzz-example
Minimal viable OSS-Fuzz integration

# To test
```
git clone https://github.com/AdaLogics/oss-fuzz-example
git clone https://github.com/google/oss-fuzz

cp -rf ./oss-fuzz-example/oss-fuzz-example oss-fuzz/projects/oss-fuzz-example
cd oss-fuzz
python3 infra/helper.py build_fuzzers oss-fuzz-example
python3 infra/helper.py run_fuzzer oss-fuzz-example simple-fuzzer
```
