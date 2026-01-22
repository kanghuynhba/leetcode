class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        
        // Map 1: Groups lines by Slope -> Line Constant (C) -> Count
        // Key 1 (Slope): pair<dy, dx> (normalized by GCD)
        // Key 2 (Line Constant C): val = dx*y - dy*x
        map<pair<int, int>, map<long long, int>> slopeMap;

        // Map 2: Groups lines by Midpoint -> Slope -> Count
        // Key 1 (Midpoint): pair<sumX, sumY>
        // Key 2 (Slope): pair<dy, dx>
        map<pair<int, int>, map<pair<int, int>, int>> midMap;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long long x1 = points[i][0], y1 = points[i][1];
                long long x2 = points[j][0], y2 = points[j][1];

                // 1. Calculate Exact Slope (dy/dx)
                long long dy = y1 - y2;
                long long dx = x1 - x2;
                
                // Normalize by GCD to store as irreducible fraction
                long long common = std::gcd(abs(dy), abs(dx));
                dy /= common;
                dx /= common;

                // Standardize signs (ensure dx is non-negative, or dy if dx is 0)
                if (dx < 0) { dx = -dx; dy = -dy; }
                else if (dx == 0 && dy < 0) { dy = -dy; }

                pair<int, int> slopeKey = {(int)dy, (int)dx};

                // 2. Calculate Exact Line Constant (C)
                // Equation: dx*y - dy*x = C
                // This value C is unique for every distinct parallel line
                long long lineC = dx * y1 - dy * x1;

                // 3. Store for Total Parallel Pairs
                slopeMap[slopeKey][lineC]++;

                // 4. Store for Parallelogram Subtraction (Midpoint)
                // We use sum (x1+x2, y1+y2) representing midpoint * 2
                pair<int, int> midKey = {(int)(x1 + x2), (int)(y1 + y2)};
                midMap[midKey][slopeKey]++;
            }
        }

        int ans = 0;

        // Step A: Add ALL parallel pairs (Trapezoids + Parallelograms)
        for (auto const& [slope, lines] : slopeMap) {
            if (lines.size() < 2) continue;
            
            // We need to pick one segment from Line A and one from Line B
            // Running Sum Algorithm
            int currentSum = 0;
            for (auto const& [lineConstant, count] : lines) {
                ans += currentSum * count;
                currentSum += count;
            }
        }

        // Step B: Subtract Parallelograms (Diagonals bisecting)
        for (auto const& [midpoint, slopes] : midMap) {
            if (slopes.size() < 2) continue;

            // We need to pick one segment with Slope A and one with Slope B
            // that share the same midpoint.
            int currentSum = 0;
            for (auto const& [slope, count] : slopes) {
                ans -= currentSum * count;
                currentSum += count;
            }
        }

        return ans;
    }
};
