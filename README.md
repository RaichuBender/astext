## astext

Easilly render binary data as printable text
With optional simple, bi-directional seed encryption

```php
Usage:
	./astext  [input filename OR - for stdin]  [output filename OR -c for stdout]  [seed value]

astext-ified data can easilly be converted back to the original binary file with printf.
Example in bash:
	$ printf "$(./astext data.bin)" > data_out.bin

Example with encryption:
	$ printf "$(printf "$(./astext data.bin -c 7777)" | ./astext - -c 7777)" > data_out.bin
```
