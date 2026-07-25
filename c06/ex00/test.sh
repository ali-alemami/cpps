#!/bin/bash
set -u

BINARY="./convert"
PASS=0
FAIL=0

GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'
CHECK="[PASS]"
CROSS="[FAIL]"

# Build
if [ -f Makefile ]; then
    make -s
else
    c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o convert
fi

if [ ! -x "$BINARY" ]; then
    echo "Build failed or $BINARY not found."
    exit 1
fi

check_case() {
    local input="$1"
    local expected_char="$2" expected_int="$3" expected_float="$4" expected_double="$5"
    local out a_char a_int a_float a_double ok

    out=$("$BINARY" "$input" 2>/dev/null)
    a_char=$(echo "$out" | grep '^char:' | sed 's/char: //')
    a_int=$(echo "$out" | grep '^int:' | sed 's/int: //')
    a_float=$(echo "$out" | grep '^float:' | sed 's/float: //')
    a_double=$(echo "$out" | grep '^double:' | sed 's/double: //')

    ok=1
    [ "$a_char" == "$expected_char" ] || ok=0
    [ "$a_int" == "$expected_int" ] || ok=0
    [ "$a_float" == "$expected_float" ] || ok=0
    [ "$a_double" == "$expected_double" ] || ok=0

    if [ "$ok" -eq 1 ]; then
        PASS=$((PASS+1))
        printf "${GREEN}${CHECK}${NC} %s\n" "\"$input\""
    else
        FAIL=$((FAIL+1))
        printf "${RED}${CROSS}${NC} %s\n" "\"$input\""
        printf "    expected -> char:%s int:%s float:%s double:%s\n" "$expected_char" "$expected_int" "$expected_float" "$expected_double"
        printf "    actual   -> char:%s int:%s float:%s double:%s\n" "$a_char" "$a_int" "$a_float" "$a_double"
    fi
}

IMP="impossible"
ND="Non displayable"

# --- char ---
check_case "a" "'a'" "97" "97.0f" "97.0"
check_case "z" "'z'" "122" "122.0f" "122.0"
check_case "A" "'A'" "65" "65.0f" "65.0"
check_case "Z" "'Z'" "90" "90.0f" "90.0"
check_case "0" "$ND" "0" "0.0f" "0.0"
check_case "9" "$ND" "9" "9.0f" "9.0"
check_case "1" "$ND" "1" "1.0f" "1.0"
check_case " " "' '" "32" "32.0f" "32.0"
check_case "!" "'!'" "33" "33.0f" "33.0"
check_case "~" "'~'" "126" "126.0f" "126.0"
check_case "'a'" "$IMP" "$IMP" "$IMP" "$IMP"
check_case "'A'" "$IMP" "$IMP" "$IMP" "$IMP"
check_case "'0'" "$IMP" "$IMP" "$IMP" "$IMP"
check_case "'a" "$IMP" "$IMP" "$IMP" "$IMP"
check_case "ab" "$IMP" "$IMP" "$IMP" "$IMP"
check_case "" "$IMP" "$IMP" "$IMP" "$IMP"

# --- int ---
check_case "-0" "$ND" "0" "0.0f" "0.0"
check_case "+0" "$ND" "0" "0.0f" "0.0"
check_case "42" "'*'" "42" "42.0f" "42.0"
check_case "-42" "$ND" "-42" "-42.0f" "-42.0"
check_case "+42" "'*'" "42" "42.0f" "42.0"
check_case "007" "$ND" "7" "7.0f" "7.0"
check_case "0042" "'*'" "42" "42.0f" "42.0"
check_case "2147483647" "$IMP" "2147483647" "2147483648.0f" "2147483647.0"
check_case "2147483648" "$IMP" "$IMP" "$IMP" "$IMP"
check_case "-2147483648" "$IMP" "-2147483648" "-2147483648.0f" "-2147483648.0"
check_case "-2147483649" "$IMP" "$IMP" "$IMP" "$IMP"
check_case "42a" "$IMP" "$IMP" "$IMP" "$IMP"
check_case "4-2" "$IMP" "$IMP" "$IMP" "$IMP"
check_case "42.0" "'*'" "42" "42.0f" "42.0"
check_case "0x2A" "$IMP" "$IMP" "$IMP" "$IMP"
check_case " 42" "$IMP" "$IMP" "$IMP" "$IMP"
check_case "42 " "$IMP" "$IMP" "$IMP" "$IMP"

# --- float ---
check_case "0.0f" "$ND" "0" "0.0f" "0.0"
check_case "-0.0f" "$ND" "0" "-0.0f" "-0.0"
check_case "+4.2f" "$ND" "4" "4.1999998f" "4.19999980926513672"
check_case "4.2f" "$ND" "4" "4.1999998f" "4.19999980926513672"
check_case "-4.2f" "$ND" "-4" "-4.1999998f" "-4.19999980926513672"
check_case "42.0f" "'*'" "42" "42.0f" "42.0"
check_case "0.f" "$ND" "0" "0.0f" "0.0"
check_case ".5f" "$ND" "0" "0.5f" "0.5"
check_case "5.f" "$ND" "5" "5.0f" "5.0"
check_case "-.5f" "$ND" "0" "-0.5f" "-0.5"
check_case "+.5f" "$ND" "0" "0.5f" "0.5"
check_case "-.0f" "$ND" "0" "-0.0f" "-0.0"
check_case "-.f" "$IMP" "$IMP" "$IMP" "$IMP"
check_case "+.f" "$IMP" "$IMP" "$IMP" "$IMP"
check_case ".f" "$IMP" "$IMP" "$IMP" "$IMP"
check_case "nanf" "$IMP" "$IMP" "nanf" "nan"
check_case "+nanf" "$IMP" "$IMP" "$IMP" "$IMP"
check_case "-nanf" "$IMP" "$IMP" "$IMP" "$IMP"
check_case "inff" "$IMP" "$IMP" "$IMP" "$IMP"
check_case "+inff" "$IMP" "$IMP" "inff" "inf"
check_case "-inff" "$IMP" "$IMP" "-inff" "-inf"
check_case "1e40f" "$IMP" "$IMP" "$IMP" "$IMP"
check_case "1e-40f" "$IMP" "$IMP" "$IMP" "$IMP"
check_case "4.2f." "$IMP" "$IMP" "$IMP" "$IMP"
check_case "4.2.f" "$IMP" "$IMP" "$IMP" "$IMP"
check_case "4.2ff" "$IMP" "$IMP" "$IMP" "$IMP"
check_case "f4.2" "$IMP" "$IMP" "$IMP" "$IMP"
check_case "4f.2" "$IMP" "$IMP" "$IMP" "$IMP"

# --- double ---
check_case "0.0" "$ND" "0" "0.0f" "0.0"
check_case "-0.0" "$ND" "0" "-0.0f" "-0.0"
check_case "+4.2" "$ND" "4" "4.1999998f" "4.20000000000000018"
check_case "4.2" "$ND" "4" "4.1999998f" "4.20000000000000018"
check_case "-4.2" "$ND" "-4" "-4.1999998f" "-4.20000000000000018"
check_case "0." "$ND" "0" "0.0f" "0.0"
check_case ".5" "$ND" "0" "0.5f" "0.5"
check_case "5." "$ND" "5" "5.0f" "5.0"
check_case "-.5" "$ND" "0" "-0.5f" "-0.5"
check_case "+.5" "$ND" "0" "0.5f" "0.5"
check_case "nan" "$IMP" "$IMP" "nanf" "nan"
check_case "+nan" "$IMP" "$IMP" "$IMP" "$IMP"
check_case "-nan" "$IMP" "$IMP" "$IMP" "$IMP"
check_case "inf" "$IMP" "$IMP" "$IMP" "$IMP"
check_case "+inf" "$IMP" "$IMP" "inff" "inf"
check_case "-inf" "$IMP" "$IMP" "-inff" "-inf"
check_case "1e308" "$IMP" "$IMP" "$IMP" "$IMP"
check_case "1e309" "$IMP" "$IMP" "$IMP" "$IMP"
check_case "1e-320" "$IMP" "$IMP" "$IMP" "$IMP"
check_case "123456789012345678901234567890.0" "$IMP" "$IMP" "123456789182729271864492818432.0f" "123456789012345677877719597056.0"
check_case "4.2." "$IMP" "$IMP" "$IMP" "$IMP"
check_case "4..2" "$IMP" "$IMP" "$IMP" "$IMP"
check_case "." "'.'" "46" "46.0f" "46.0"
check_case ".." "$IMP" "$IMP" "$IMP" "$IMP"

# --- Extreme Limits & Overflows ---
check_case "127" "$ND" "127" "127.0f" "127.0"
check_case "128" "$IMP" "128" "128.0f" "128.0"
check_case "-128" "$ND" "-128" "-128.0f" "-128.0"
check_case "-129" "$IMP" "-129" "-129.0f" "-129.0"
check_case "2147483647.0" "$IMP" "2147483647" "2147483648.0f" "2147483647.0"
check_case "-2147483648.0" "$IMP" "-2147483648" "-2147483648.0f" "-2147483648.0"
check_case "2147483648.0" "$IMP" "$IMP" "2147483648.0f" "2147483648.0"
check_case "-2147483649.0" "$IMP" "$IMP" "-2147483648.0f" "-2147483649.0"
check_case "3000000000.0" "$IMP" "$IMP" "3000000000.0f" "3000000000.0"
check_case "-3000000000.0" "$IMP" "$IMP" "-3000000000.0f" "-3000000000.0"
check_case "3000000000.0f" "$IMP" "$IMP" "3000000000.0f" "3000000000.0"
check_case "-3000000000.0f" "$IMP" "$IMP" "-3000000000.0f" "-3000000000.0"
check_case "9223372036854775807" "$IMP" "$IMP" "$IMP" "$IMP"
check_case "-9223372036854775808" "$IMP" "$IMP" "$IMP" "$IMP"
check_case "999999999999999999999999999" "$IMP" "$IMP" "$IMP" "$IMP"
check_case "-999999999999999999999999999" "$IMP" "$IMP" "$IMP" "$IMP"
# 241 nines: ~1e241, well within DBL_MAX (~1.8e308) -> double parses fine, no ERANGE.
# Only overflows on the downstream cast to float/int/char, not double itself.
BIG_BUT_VALID_DOUBLE="9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999.0"
check_case "$BIG_BUT_VALID_DOUBLE" "$IMP" "$IMP" "$IMP" "10000000000000000509610295637002728139855252735311366616309601643306774209564163318419090863889067021760658106681756277614179911327452208591182514380241927357631043882428148314438094801465785761804352561506118922744139467759619125060885807104.0"

# 310 nines: genuinely exceeds DBL_MAX -> real ERANGE overflow in strtod itself, so all four are impossible.
TRUE_OVERFLOW_DOUBLE="9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999.0"
check_case "$TRUE_OVERFLOW_DOUBLE" "$IMP" "$IMP" "$IMP" "$IMP"
check_case "000000.0000000" "$ND" "0" "0.0f" "0.0"
check_case "-0000.000f" "$ND" "0" "-0.0f" "-0.0"

# --- Float type limits (FLT_MAX / FLT_MIN, verified in-range: no ERANGE on strtof) ---
check_case "340282346638528859811704183484516925440.0f" "$IMP" "$IMP" "340282346638528859811704183484516925440.0f" "340282346638528859811704183484516925440.0"
check_case "-340282346638528859811704183484516925440.0f" "$IMP" "$IMP" "-340282346638528859811704183484516925440.0f" "-340282346638528859811704183484516925440.0"
check_case "0.000000000000000000000000000000000000011754944f" "$ND" "0" "0.0f" "0.0"

# --- Float Rounding Boundaries (Double > FLT_MAX but rounds down to FLT_MAX) ---
check_case "340282347638528874859170403361205780480.0" "$IMP" "$IMP" "340282346638528859811704183484516925440.0f" "340282347638528874859170403361205780480.0"
check_case "-340282347638528874859170403361205780480.0" "$IMP" "$IMP" "-340282346638528859811704183484516925440.0f" "-340282347638528874859170403361205780480.0"
check_case "340282347638528874859170403361205780480.0f" "$IMP" "$IMP" "340282346638528859811704183484516925440.0f" "340282346638528859811704183484516925440.0"
check_case "-340282347638528874859170403361205780480.0f" "$IMP" "$IMP" "-340282346638528859811704183484516925440.0f" "-340282346638528859811704183484516925440.0"
# --- Float->Int boundary precision (exact INT_MIN case) ---
# static_cast<float>(INT_MIN) rounds to -2147483648.0f exactly.
# A naive `- 1.0f` buffer computed in float rounds right back to the same
# value (float spacing near 2^31 is 256), so INT_MIN itself must still be
# accepted as a valid int, not reported impossible.
check_case "-2147483648.0f" "$IMP" "-2147483648" "-2147483648.0f" "-2147483648.0"
check_case "-2147483647.0f" "$IMP" "-2147483648" "-2147483648.0f" "-2147483648.0"
check_case "-2147483649.0f" "$IMP" "-2147483648" "-2147483648.0f" "-2147483648.0"

# --- garbage ---
check_case "-" "'-'" "45" "45.0f" "45.0"
check_case "+" "'+'" "43" "43.0f" "43.0"
check_case "f" "'f'" "102" "102.0f" "102.0"
check_case "abc" "$IMP" "$IMP" "$IMP" "$IMP"
check_case "- 42" "$IMP" "$IMP" "$IMP" "$IMP"
check_case "+ 42" "$IMP" "$IMP" "$IMP" "$IMP"
check_case "--42" "$IMP" "$IMP" "$IMP" "$IMP"
check_case "++42" "$IMP" "$IMP" "$IMP" "$IMP"
check_case "NaN" "$IMP" "$IMP" "$IMP" "$IMP"
check_case "INF" "$IMP" "$IMP" "$IMP" "$IMP"
check_case "null" "$IMP" "$IMP" "$IMP" "$IMP"
check_case $'42\n' "$IMP" "$IMP" "$IMP" "$IMP"
check_case $'\t42' "$IMP" "$IMP" "$IMP" "$IMP"

# --- Decimal Truncation Boundaries ---
check_case "127.9" "$ND" "127" "127.9000015f" "127.90000000000000568"
check_case "-128.9" "$ND" "-128" "-128.8999939f" "-128.90000000000000568"
check_case "127.9f" "$ND" "127" "127.9000015f" "127.90000152587890625"
check_case "-128.9f" "$ND" "-128" "-128.8999939f" "-128.899993896484375"

echo ""
echo "==================="
if [ "$FAIL" -eq 0 ]; then
    printf "${GREEN}PASS: %d  FAIL: %d${NC}\n" "$PASS" "$FAIL"
else
    printf "${RED}PASS: %d  FAIL: %d${NC}\n" "$PASS" "$FAIL"
fi