#!/bin/bash

# Setup script for CodeChella Running Sum Challenge
# This script helps set up the environment for the challenge

echo "=== CodeChella Running Sum Challenge Setup ==="
echo ""

# Colors for output
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

echo -e "${BLUE}Setting up the challenge environment...${NC}"
echo ""

# Check for required tools
echo "Checking for required tools..."

# Check C/C++ compiler
if command -v gcc &> /dev/null; then
    echo -e "${GREEN}✓ GCC found${NC}"
else
    echo -e "${YELLOW}⚠ GCC not found - C compilation will fail${NC}"
fi

if command -v g++ &> /dev/null; then
    echo -e "${GREEN}✓ G++ found${NC}"
else
    echo -e "${YELLOW}⚠ G++ not found - C++ compilation will fail${NC}"
fi

# Check .NET
if command -v dotnet &> /dev/null; then
    echo -e "${GREEN}✓ .NET SDK found${NC}"
else
    echo -e "${YELLOW}⚠ .NET SDK not found - C# compilation will fail${NC}"
fi

# Check Go
if command -v go &> /dev/null; then
    echo -e "${GREEN}✓ Go found${NC}"
else
    echo -e "${YELLOW}⚠ Go not found - Go compilation will fail${NC}"
fi

# Check Java
if command -v javac &> /dev/null; then
    echo -e "${GREEN}✓ Java compiler found${NC}"
else
    echo -e "${YELLOW}⚠ Java compiler not found - Java compilation will fail${NC}"
fi

# Check Node.js
if command -v node &> /dev/null; then
    echo -e "${GREEN}✓ Node.js found${NC}"
else
    echo -e "${YELLOW}⚠ Node.js not found - JavaScript/TypeScript will fail${NC}"
fi

# Check Python
if command -v python3 &> /dev/null; then
    echo -e "${GREEN}✓ Python 3 found${NC}"
else
    echo -e "${YELLOW}⚠ Python 3 not found - Python will fail${NC}"
fi

# Check Rust
if command -v cargo &> /dev/null; then
    echo -e "${GREEN}✓ Rust/Cargo found${NC}"
else
    echo -e "${YELLOW}⚠ Rust/Cargo not found - Rust compilation will fail${NC}"
fi

echo ""
echo -e "${BLUE}Setting up example solutions...${NC}"

# Create example solutions for team 1
echo "Creating example solutions for Team 1..."

# C example
cat > team_1/c/main.c << 'EOF'
#include <stdio.h>
#include <stdint.h>

// Function to calculate running sum from 1 to n
// Using the mathematical formula: n * (n + 1) / 2
long long calculate_running_sum(int n) {
    return (long long)n * (n + 1) / 2;
}

int main() {
    int n;
    scanf("%d", &n);
    
    long long result = calculate_running_sum(n);
    printf("%lld\n", result);
    
    return 0;
}
EOF

# Python example
cat > team_1/py/main.py << 'EOF'
# Function to calculate running sum from 1 to n
# Using the mathematical formula: n * (n + 1) / 2
def calculate_running_sum(n):
    return n * (n + 1) // 2

if __name__ == "__main__":
    n = int(input())
    result = calculate_running_sum(n)
    print(result)
EOF

echo -e "${GREEN}✓ Example solutions created${NC}"
echo ""

echo -e "${BLUE}Testing the setup...${NC}"

# Test C example
echo "Testing C example..."
cd team_1/c
if make test > /dev/null 2>&1; then
    echo -e "${GREEN}✓ C example works${NC}"
else
    echo -e "${YELLOW}⚠ C example failed${NC}"
fi
cd ../..

# Test Python example
echo "Testing Python example..."
cd team_1/py
if ./test.sh > /dev/null 2>&1; then
    echo -e "${GREEN}✓ Python example works${NC}"
else
    echo -e "${YELLOW}⚠ Python example failed${NC}"
fi
cd ../..

echo ""
echo -e "${GREEN}🎉 Setup complete!${NC}"
echo ""
echo "Next steps:"
echo "1. Students can start implementing solutions in their language folders"
echo "2. Use './run_all_tests.sh' to check all languages"
echo "3. Use './run_all_tests.sh [language]' to check specific language"
echo ""
echo "Example usage:"
echo "  ./run_all_tests.sh          # Check all languages"
echo "  ./run_all_tests.sh python   # Check Python specifically"
echo "  ./run_all_tests.sh cpp      # Check C++ specifically"
echo ""
echo "Good luck with the challenge! 🚀"
