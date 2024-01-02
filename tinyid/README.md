# Tinyid

A bit.ly-like tiny ID generator has been developed by porting [short_url.py](https://github.com/mozillazg/ShortURL/blob/master/shorturl/libs/short_url.py).
This generator employs a bit-shuffling approach to prevent the generation of consecutive, predictable URLs.
Importantly, the algorithm is deterministic and guarantees no collisions.
