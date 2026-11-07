# QuickFeather

QuickFeather is an x86_64 kernel. It's a project I undertook to create my own Linux from scratch and demonstrate my skills...

It's not Linux itself, but it took inspiration from it because of its monolithic architecture.

# How do I compile the kernel? (if I want to compile it for another architecture)

 First you should install qemu, only if you're going to do tests, then if you're serious: nasm, clang and linkerld...

Then just go to ~/QuickFeather/ and run(This will generate a .bin file in case you later want to create an .iso file using grub):

`bash 
./compile.sh
`
Then, if you're going to do tests with qemu, you do the following:
`bash
./run.sh
`

 And that's all :)
