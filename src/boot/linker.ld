ENTRY(_start)

SECTIONS
{
    . = 1M;

    /* The Multiboot2 header is placed at the beginning */
    .multiboot2_header : {
        *(.multiboot2_header)
    }

    /* The text section (kernel code) starts after the Multiboot2 header */
    .text : {
        *(.text)
    }

    /* Read-only data. */
	.rodata BLOCK(4K) : ALIGN(4K)
	{
		*(.rodata)
	}

	/* Read-write data (initialized) */
	.data BLOCK(4K) : ALIGN(4K)
	{
		*(.data)
	}

	/* Read-write data (uninitialized) and stack */
	.bss BLOCK(4K) : ALIGN(4K)
	{
		*(COMMON)
		*(.bss)
	}
}
