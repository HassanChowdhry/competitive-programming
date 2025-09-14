#!/bin/bash

# Simple CodeChella Running Sum Challenge - Language Checker
# Usage: ./run_all_tests.sh [language]

echo "=== CodeChella Running Sum Challenge ==="
echo ""

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Function to check if a language directory exists and has a main file
check_language() {
    local lang=$1
    local lang_dir="$lang"
    
    if [ ! -d "$lang_dir" ]; then
        echo -e "${RED}✗ $lang: Directory not found${NC}"
        return 1
    fi
    
    # Check for main file based on language
    local main_file=""
    case $lang in
        "c")
            main_file="main.c"
            ;;
        "cpp")
            main_file="main.cpp"
            ;;
        "cs")
            main_file="main.cs"
            ;;
        "go")
            main_file="main.go"
            ;;
        "java")
            main_file="Main.java"
            ;;
        "js")
            main_file="main.js"
            ;;
        "py")
            main_file="main.py"
            ;;
        "rs")
            main_file="main.rs"
            ;;
        *)
            echo -e "${RED}✗ Unknown language: $lang${NC}"
            return 1
            ;;
    esac
    
    if [ -f "$lang_dir/$main_file" ]; then
        echo -e "${GREEN}✓ $lang: $main_file found${NC}"
        return 0
    else
        echo -e "${RED}✗ $lang: $main_file not found${NC}"
        return 1
    fi
}

# Function to check all languages
check_all_languages() {
    local total_langs=0
    local found_langs=0
    
    for lang in c cpp cs go java js py rs; do
        total_langs=$((total_langs + 1))
        if check_language $lang; then
            found_langs=$((found_langs + 1))
        fi
    done
    
    echo ""
    echo "=== SUMMARY ==="
    echo -e "Total languages: $total_langs"
    echo -e "Found: ${GREEN}$found_langs${NC}"
    echo -e "Missing: ${RED}$((total_langs - found_langs))${NC}"
    
    if [ $found_langs -eq $total_langs ]; then
        echo -e "${GREEN}🎉 All language files found!${NC}"
        return 0
    else
        echo -e "${RED}❌ Some language files are missing${NC}"
        return 1
    fi
}

# Main script logic
if [ $# -eq 0 ]; then
    # No arguments - check all languages
    check_all_languages
elif [ $# -eq 1 ]; then
    # One argument - check specific language
    check_language $1
else
    echo "Usage: $0 [language]"
    echo "       $0 (checks all languages)"
    echo ""
    echo "Languages: c, cpp, cs, go, java, js, py, rs"
    exit 1
fi
