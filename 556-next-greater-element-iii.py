class Solution:
    def nextGreaterElement(self, n: int) -> int:
      s = str(n)
      k = 1 << 31
      for p in itertools.permutations(s):
        pn = int(''.join(p))
        if n < pn < k:
          k = pn
      return -1 if k == 1 << 31 else k
