# 导入模块
from typing import List

# 定义函数 need_evicite，判断缓存中是否需要添加新元素
def need_evicite(vec: List[int], a: int) -> bool:
    for i in range(len(vec)):
        if vec[i] == a:
            return False
    return True

# 定义函数 ifFF，判断缓存中的元素是否在后续请求中出现过
def ifFF(vecc: List[int], vecr: List[int], pos: int, newvecc: List[int]) -> bool:
    num = 0
    for i in range(len(vecc)):
        m = 0
        for j in range(pos + 1, len(vecr)):
            if vecr[j] == vecc[i]:
                m += 1
                num += 1
                break
        if m == 0:
            newvecc.append(vecc[i])
    return num != len(vecc)

# 定义函数 getpos1，获取元素 a 在请求序列中的位置
def getpos1(vec: List[int], pos: int, a: int) -> int:
    for i in range(pos + 1, len(vec)):
        if vec[i] == a:
            return i
    return -1

# 定义函数 getpos2，获取元素 a 在请求序列中最后一次出现的位置
def getpos2(vec: List[int], pos: int, a: int) -> int:
    m = 0
    for i in range(pos):
        if vec[i] == a:
            m = i
    return m

# 主程序部分
if __name__ == '__main__':
    # 输入缓存大小 k，缓存初始元素个数 n 和请求序列长度 s
    k, n, s = map(int, input().split())
    
    # 输入缓存初始元素并存入列表 cache 中
    cache = list(map(int, input().split()))
    
    # 输入请求序列并存入列表 requests 中
    requests = list(map(int, input().split()))

    # 遍历请求序列中的每个元素
    for i in range(len(requests)):
        # 如果缓存未满且当前请求不在缓存中，则将当前请求加入缓存中
        if len(cache) < k and need_evicite(cache, requests[i]):
            cache.append(requests[i])
        # 如果当前请求已经在缓存中，则跳过此次循环，继续下一次循环
        elif not need_evicite(cache, requests[i]):
            continue
        # 如果当前请求不在缓存中且缓存已满，则需要进行替换操作
        elif need_evicite(cache, requests[i]) and len(cache) == k:
            newcache = []
            # 如果所有缓存中的元素都在后续请求中出现过，则执行 LRU 算法（Least Recently Used）
            if not ifFF(cache, requests, i, newcache):
                max_value = -1
                far = -1 
                d = [0] * k 
                for j in range(k):
                    d[j] = getpos1(requests, i, cache[j])
                    if d[j] > max_value:
                        max_value = d[j]
                        far = j 
                print(cache[far], end=' ')
                cache[far] = requests[i]
            else:
                min_value = 10000 
                far = -1 
                d = [0] * len(newcache)
                for j in range(len(newcache)):
                    d[j] = getpos2(requests, i,newcache[j])
                    if d[j] < min_value:
                        min_value=d[j]
                        far=j 
                print(newcache[far], end=' ')
                for j in range(len(cache)):
                    if cache[j]==newcache[far]:
                        cache[j]=requests[i]
                        break