def solution(N, K, candle):
    start = 0
    end = 0
    
    candle_counter = {i: 0 for i in range(1, K+1)}
    unique_candles_seen = set()
    
    min_length = float('inf')

    while end < N:
        # If the candle at the 'end' position is one we're interested in
        if 1 <= candle[end] <= K:
            # Increase the counter for this candle
            candle_counter[candle[end]] += 1
            
            # If this is the first time we're seeing this candle in the current segment
            if candle_counter[candle[end]] == 1:
                unique_candles_seen.add(candle[end])

        # If the current segment contains all candles from 1 to K
        while len(unique_candles_seen) == K:
            min_length = min(min_length, end - start + 1)
            
            # Reduce the count of the candle at the 'start' position
            if 1 <= candle[start] <= K:
                candle_counter[candle[start]] -= 1
                
                # If we've just removed the last occurrence of this candle from the current segment
                if candle_counter[candle[start]] == 0:
                    unique_candles_seen.remove(candle[start])
            
            start += 1

        end += 1

    return min_length

# Sample input
N = 7
K = 3
candle = [4, 5, 3, 1, 7, 2, 6]

print(solution(N, K, candle))  # Expected output: 4
