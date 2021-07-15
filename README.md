# Address Sanitizer Diagnostics

## Test case 101_PW_15_f_pseudopots

### On process id asan.2386

```bash

=================================================================
==2386==ERROR: LeakSanitizer: detected memory leaks

Direct leak of 20736 byte(s) in 6 object(s) allocated from:
    #0 0x7f211d66fef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x560dd00b2e57 in Symmetry::rho_symmetry(double*, int const&, int const&, int const&) source/src_pw/symmetry.cpp:1440
    #2 0x560dd00ded7b in Symmetry_rho::psymm(double*) const source/src_pw/symmetry_rho.cpp:40
    #3 0x560dd00df170 in Symmetry_rho::begin(int const&) const source/src_pw/symmetry_rho.cpp:21
    #4 0x560dcffb637c in Electrons::self_consistent(int const&) source/src_pw/electrons.cpp:236
    #5 0x560dcfc2003c in Ions::opt_ions_pw() source/src_ions/ions.cpp:131
    #6 0x560dcfc11b21 in Cell_PW::opt_cells_pw() source/src_ions/Cell_PW.cpp:78
    #7 0x560dd04d1f7a in Run_pw::plane_wave_line() source/run_pw.cpp:104
    #8 0x560dd049330c in Driver::atomic_world() source/driver.cpp:85
    #9 0x560dd04964c4 in Driver::init() source/driver.cpp:27
    #10 0x560dcf7e1921 in calculate() source/main.cpp:35
    #11 0x560dcf7e226e in main source/main.cpp:18
    #12 0x7f211bd2509a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 3456 byte(s) in 1 object(s) allocated from:
    #0 0x7f211d66fef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x560dd00b2e57 in Symmetry::rho_symmetry(double*, int const&, int const&, int const&) source/src_pw/symmetry.cpp:1440
    #2 0x560dd00ded7b in Symmetry_rho::psymm(double*) const source/src_pw/symmetry_rho.cpp:40
    #3 0x560dd00df170 in Symmetry_rho::begin(int const&) const source/src_pw/symmetry_rho.cpp:21
    #4 0x560dcffb5c90 in Electrons::self_consistent(int const&) source/src_pw/electrons.cpp:130
    #5 0x560dcfc2003c in Ions::opt_ions_pw() source/src_ions/ions.cpp:131
    #6 0x560dcfc11b21 in Cell_PW::opt_cells_pw() source/src_ions/Cell_PW.cpp:78
    #7 0x560dd04d1f7a in Run_pw::plane_wave_line() source/run_pw.cpp:104
    #8 0x560dd049330c in Driver::atomic_world() source/driver.cpp:85
    #9 0x560dd04964c4 in Driver::init() source/driver.cpp:27
    #10 0x560dcf7e1921 in calculate() source/main.cpp:35
    #11 0x560dcf7e226e in main source/main.cpp:18
    #12 0x7f211bd2509a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 8 byte(s) in 1 object(s) allocated from:
    #0 0x7f211d66e330 in __interceptor_malloc (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xe9330)
    #1 0x7f211c398cd2  (/usr/lib/x86_64-linux-gnu/libmpich.so.12+0x161cd2)

Direct leak of 8 byte(s) in 1 object(s) allocated from:
    #0 0x7f211d66e330 in __interceptor_malloc (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xe9330)
    #1 0x7f211c398cb6  (/usr/lib/x86_64-linux-gnu/libmpich.so.12+0x161cb6)

SUMMARY: AddressSanitizer: 24208 byte(s) leaked in 9 allocation(s).
```

### On process id asan.2387

```bash

=================================================================
==2387==ERROR: LeakSanitizer: detected memory leaks

Direct leak of 40 byte(s) in 1 object(s) allocated from:
    #0 0x7fc5bc04aef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x5623e67a64bd in pseudo_nc::pseudo_nc() source/module_cell/pseudo_nc.cpp:6
    #2 0x5623e679937b in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:4
    #3 0x5623e67a0eef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #4 0x5623e67ea1c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #5 0x5623e7404228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #6 0x5623e73c630c in Driver::atomic_world() source/driver.cpp:85
    #7 0x5623e73c94c4 in Driver::init() source/driver.cpp:27
    #8 0x5623e6714921 in calculate() source/main.cpp:35
    #9 0x5623e671526e in main source/main.cpp:18
    #10 0x7fc5ba70009a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 12 byte(s) in 1 object(s) allocated from:
    #0 0x7fc5bc04aef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x5623e67994bc in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:6
    #2 0x5623e67a0eef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #3 0x5623e67ea1c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #4 0x5623e7404228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #5 0x5623e73c630c in Driver::atomic_world() source/driver.cpp:85
    #6 0x5623e73c94c4 in Driver::init() source/driver.cpp:27
    #7 0x5623e6714921 in calculate() source/main.cpp:35
    #8 0x5623e671526e in main source/main.cpp:18
    #9 0x7fc5ba70009a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 8 byte(s) in 1 object(s) allocated from:
    #0 0x7fc5bc04aef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x5623e67a663f in pseudo_nc::pseudo_nc() source/module_cell/pseudo_nc.cpp:9
    #2 0x5623e679937b in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:4
    #3 0x5623e67a0eef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #4 0x5623e67ea1c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #5 0x5623e7404228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #6 0x5623e73c630c in Driver::atomic_world() source/driver.cpp:85
    #7 0x5623e73c94c4 in Driver::init() source/driver.cpp:27
    #8 0x5623e6714921 in calculate() source/main.cpp:35
    #9 0x5623e671526e in main source/main.cpp:18
    #10 0x7fc5ba70009a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 8 byte(s) in 1 object(s) allocated from:
    #0 0x7fc5bc04aef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x5623e67a67d3 in pseudo_nc::pseudo_nc() source/module_cell/pseudo_nc.cpp:22
    #2 0x5623e679937b in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:4
    #3 0x5623e67a0eef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #4 0x5623e67ea1c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #5 0x5623e7404228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #6 0x5623e73c630c in Driver::atomic_world() source/driver.cpp:85
    #7 0x5623e73c94c4 in Driver::init() source/driver.cpp:27
    #8 0x5623e6714921 in calculate() source/main.cpp:35
    #9 0x5623e671526e in main source/main.cpp:18
    #10 0x7fc5ba70009a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 8 byte(s) in 1 object(s) allocated from:
    #0 0x7fc5bc04aef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x5623e67a670a in pseudo_nc::pseudo_nc() source/module_cell/pseudo_nc.cpp:16
    #2 0x5623e679937b in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:4
    #3 0x5623e67a0eef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #4 0x5623e67ea1c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #5 0x5623e7404228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #6 0x5623e73c630c in Driver::atomic_world() source/driver.cpp:85
    #7 0x5623e73c94c4 in Driver::init() source/driver.cpp:27
    #8 0x5623e6714921 in calculate() source/main.cpp:35
    #9 0x5623e671526e in main source/main.cpp:18
    #10 0x7fc5ba70009a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 8 byte(s) in 1 object(s) allocated from:
    #0 0x7fc5bc04aef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x5623e67a6746 in pseudo_nc::pseudo_nc() source/module_cell/pseudo_nc.cpp:19
    #2 0x5623e679937b in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:4
    #3 0x5623e67a0eef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #4 0x5623e67ea1c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #5 0x5623e7404228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #6 0x5623e73c630c in Driver::atomic_world() source/driver.cpp:85
    #7 0x5623e73c94c4 in Driver::init() source/driver.cpp:27
    #8 0x5623e6714921 in calculate() source/main.cpp:35
    #9 0x5623e671526e in main source/main.cpp:18
    #10 0x7fc5ba70009a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 8 byte(s) in 1 object(s) allocated from:
    #0 0x7fc5bc04aef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x5623e67a67a4 in pseudo_nc::pseudo_nc() source/module_cell/pseudo_nc.cpp:21
    #2 0x5623e679937b in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:4
    #3 0x5623e67a0eef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #4 0x5623e67ea1c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #5 0x5623e7404228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #6 0x5623e73c630c in Driver::atomic_world() source/driver.cpp:85
    #7 0x5623e73c94c4 in Driver::init() source/driver.cpp:27
    #8 0x5623e6714921 in calculate() source/main.cpp:35
    #9 0x5623e671526e in main source/main.cpp:18
    #10 0x7fc5ba70009a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 8 byte(s) in 1 object(s) allocated from:
    #0 0x7fc5bc04aef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x5623e67a6775 in pseudo_nc::pseudo_nc() source/module_cell/pseudo_nc.cpp:20
    #2 0x5623e679937b in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:4
    #3 0x5623e67a0eef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #4 0x5623e67ea1c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #5 0x5623e7404228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #6 0x5623e73c630c in Driver::atomic_world() source/driver.cpp:85
    #7 0x5623e73c94c4 in Driver::init() source/driver.cpp:27
    #8 0x5623e6714921 in calculate() source/main.cpp:35
    #9 0x5623e671526e in main source/main.cpp:18
    #10 0x7fc5ba70009a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 8 byte(s) in 1 object(s) allocated from:
    #0 0x7fc5bc04aef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x5623e67a666e in pseudo_nc::pseudo_nc() source/module_cell/pseudo_nc.cpp:10
    #2 0x5623e679937b in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:4
    #3 0x5623e67a0eef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #4 0x5623e67ea1c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #5 0x5623e7404228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #6 0x5623e73c630c in Driver::atomic_world() source/driver.cpp:85
    #7 0x5623e73c94c4 in Driver::init() source/driver.cpp:27
    #8 0x5623e6714921 in calculate() source/main.cpp:35
    #9 0x5623e671526e in main source/main.cpp:18
    #10 0x7fc5ba70009a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 8 byte(s) in 1 object(s) allocated from:
    #0 0x7fc5bc04aef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x5623e67a6610 in pseudo_nc::pseudo_nc() source/module_cell/pseudo_nc.cpp:8
    #2 0x5623e679937b in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:4
    #3 0x5623e67a0eef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #4 0x5623e67ea1c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #5 0x5623e7404228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #6 0x5623e73c630c in Driver::atomic_world() source/driver.cpp:85
    #7 0x5623e73c94c4 in Driver::init() source/driver.cpp:27
    #8 0x5623e6714921 in calculate() source/main.cpp:35
    #9 0x5623e671526e in main source/main.cpp:18
    #10 0x7fc5ba70009a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 4 byte(s) in 1 object(s) allocated from:
    #0 0x7fc5bc04aef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x5623e67a6802 in pseudo_nc::pseudo_nc() source/module_cell/pseudo_nc.cpp:25
    #2 0x5623e679937b in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:4
    #3 0x5623e67a0eef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #4 0x5623e67ea1c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #5 0x5623e7404228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #6 0x5623e73c630c in Driver::atomic_world() source/driver.cpp:85
    #7 0x5623e73c94c4 in Driver::init() source/driver.cpp:27
    #8 0x5623e6714921 in calculate() source/main.cpp:35
    #9 0x5623e671526e in main source/main.cpp:18
    #10 0x7fc5ba70009a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 4 byte(s) in 1 object(s) allocated from:
    #0 0x7fc5bc04aef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x5623e67a669d in pseudo_nc::pseudo_nc() source/module_cell/pseudo_nc.cpp:11
    #2 0x5623e679937b in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:4
    #3 0x5623e67a0eef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #4 0x5623e67ea1c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #5 0x5623e7404228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #6 0x5623e73c630c in Driver::atomic_world() source/driver.cpp:85
    #7 0x5623e73c94c4 in Driver::init() source/driver.cpp:27
    #8 0x5623e6714921 in calculate() source/main.cpp:35
    #9 0x5623e671526e in main source/main.cpp:18
    #10 0x7fc5ba70009a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 4 byte(s) in 1 object(s) allocated from:
    #0 0x7fc5bc04aef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x5623e67a65c2 in pseudo_nc::pseudo_nc() source/module_cell/pseudo_nc.cpp:7
    #2 0x5623e679937b in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:4
    #3 0x5623e67a0eef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #4 0x5623e67ea1c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #5 0x5623e7404228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #6 0x5623e73c630c in Driver::atomic_world() source/driver.cpp:85
    #7 0x5623e73c94c4 in Driver::init() source/driver.cpp:27
    #8 0x5623e6714921 in calculate() source/main.cpp:35
    #9 0x5623e671526e in main source/main.cpp:18
    #10 0x7fc5ba70009a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

SUMMARY: AddressSanitizer: 128 byte(s) leaked in 13 allocation(s).
```

## Test case 101_PW_15_pseudopots

### On process id asan.2473

```bash

=================================================================
==2473==ERROR: LeakSanitizer: detected memory leaks

Direct leak of 31104 byte(s) in 9 object(s) allocated from:
    #0 0x7f914976eef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x55dc24677e57 in Symmetry::rho_symmetry(double*, int const&, int const&, int const&) source/src_pw/symmetry.cpp:1440
    #2 0x55dc246a3d7b in Symmetry_rho::psymm(double*) const source/src_pw/symmetry_rho.cpp:40
    #3 0x55dc246a4170 in Symmetry_rho::begin(int const&) const source/src_pw/symmetry_rho.cpp:21
    #4 0x55dc2457b37c in Electrons::self_consistent(int const&) source/src_pw/electrons.cpp:236
    #5 0x55dc241e503c in Ions::opt_ions_pw() source/src_ions/ions.cpp:131
    #6 0x55dc241d6b21 in Cell_PW::opt_cells_pw() source/src_ions/Cell_PW.cpp:78
    #7 0x55dc24a96f7a in Run_pw::plane_wave_line() source/run_pw.cpp:104
    #8 0x55dc24a5830c in Driver::atomic_world() source/driver.cpp:85
    #9 0x55dc24a5b4c4 in Driver::init() source/driver.cpp:27
    #10 0x55dc23da6921 in calculate() source/main.cpp:35
    #11 0x55dc23da726e in main source/main.cpp:18
    #12 0x7f9147e2409a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 3456 byte(s) in 1 object(s) allocated from:
    #0 0x7f914976eef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x55dc24677e57 in Symmetry::rho_symmetry(double*, int const&, int const&, int const&) source/src_pw/symmetry.cpp:1440
    #2 0x55dc246a3d7b in Symmetry_rho::psymm(double*) const source/src_pw/symmetry_rho.cpp:40
    #3 0x55dc246a4170 in Symmetry_rho::begin(int const&) const source/src_pw/symmetry_rho.cpp:21
    #4 0x55dc2457ac90 in Electrons::self_consistent(int const&) source/src_pw/electrons.cpp:130
    #5 0x55dc241e503c in Ions::opt_ions_pw() source/src_ions/ions.cpp:131
    #6 0x55dc241d6b21 in Cell_PW::opt_cells_pw() source/src_ions/Cell_PW.cpp:78
    #7 0x55dc24a96f7a in Run_pw::plane_wave_line() source/run_pw.cpp:104
    #8 0x55dc24a5830c in Driver::atomic_world() source/driver.cpp:85
    #9 0x55dc24a5b4c4 in Driver::init() source/driver.cpp:27
    #10 0x55dc23da6921 in calculate() source/main.cpp:35
    #11 0x55dc23da726e in main source/main.cpp:18
    #12 0x7f9147e2409a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 8 byte(s) in 1 object(s) allocated from:
    #0 0x7f914976d330 in __interceptor_malloc (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xe9330)
    #1 0x7f9148497cd2  (/usr/lib/x86_64-linux-gnu/libmpich.so.12+0x161cd2)

Direct leak of 8 byte(s) in 1 object(s) allocated from:
    #0 0x7f914976d330 in __interceptor_malloc (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xe9330)
    #1 0x7f9148497cb6  (/usr/lib/x86_64-linux-gnu/libmpich.so.12+0x161cb6)

SUMMARY: AddressSanitizer: 34576 byte(s) leaked in 12 allocation(s).
```

### On process id asan.2474

```bash

=================================================================
==2474==ERROR: LeakSanitizer: detected memory leaks

Direct leak of 40 byte(s) in 1 object(s) allocated from:
    #0 0x7f2f1d3c0ef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x564d5afd54bd in pseudo_nc::pseudo_nc() source/module_cell/pseudo_nc.cpp:6
    #2 0x564d5afc837b in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:4
    #3 0x564d5afcfeef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #4 0x564d5b0191c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #5 0x564d5bc33228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #6 0x564d5bbf530c in Driver::atomic_world() source/driver.cpp:85
    #7 0x564d5bbf84c4 in Driver::init() source/driver.cpp:27
    #8 0x564d5af43921 in calculate() source/main.cpp:35
    #9 0x564d5af4426e in main source/main.cpp:18
    #10 0x7f2f1ba7609a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 12 byte(s) in 1 object(s) allocated from:
    #0 0x7f2f1d3c0ef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x564d5afc84bc in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:6
    #2 0x564d5afcfeef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #3 0x564d5b0191c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #4 0x564d5bc33228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #5 0x564d5bbf530c in Driver::atomic_world() source/driver.cpp:85
    #6 0x564d5bbf84c4 in Driver::init() source/driver.cpp:27
    #7 0x564d5af43921 in calculate() source/main.cpp:35
    #8 0x564d5af4426e in main source/main.cpp:18
    #9 0x7f2f1ba7609a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 8 byte(s) in 1 object(s) allocated from:
    #0 0x7f2f1d3c0ef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x564d5afd563f in pseudo_nc::pseudo_nc() source/module_cell/pseudo_nc.cpp:9
    #2 0x564d5afc837b in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:4
    #3 0x564d5afcfeef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #4 0x564d5b0191c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #5 0x564d5bc33228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #6 0x564d5bbf530c in Driver::atomic_world() source/driver.cpp:85
    #7 0x564d5bbf84c4 in Driver::init() source/driver.cpp:27
    #8 0x564d5af43921 in calculate() source/main.cpp:35
    #9 0x564d5af4426e in main source/main.cpp:18
    #10 0x7f2f1ba7609a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 8 byte(s) in 1 object(s) allocated from:
    #0 0x7f2f1d3c0ef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x564d5afd57d3 in pseudo_nc::pseudo_nc() source/module_cell/pseudo_nc.cpp:22
    #2 0x564d5afc837b in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:4
    #3 0x564d5afcfeef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #4 0x564d5b0191c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #5 0x564d5bc33228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #6 0x564d5bbf530c in Driver::atomic_world() source/driver.cpp:85
    #7 0x564d5bbf84c4 in Driver::init() source/driver.cpp:27
    #8 0x564d5af43921 in calculate() source/main.cpp:35
    #9 0x564d5af4426e in main source/main.cpp:18
    #10 0x7f2f1ba7609a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 8 byte(s) in 1 object(s) allocated from:
    #0 0x7f2f1d3c0ef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x564d5afd570a in pseudo_nc::pseudo_nc() source/module_cell/pseudo_nc.cpp:16
    #2 0x564d5afc837b in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:4
    #3 0x564d5afcfeef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #4 0x564d5b0191c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #5 0x564d5bc33228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #6 0x564d5bbf530c in Driver::atomic_world() source/driver.cpp:85
    #7 0x564d5bbf84c4 in Driver::init() source/driver.cpp:27
    #8 0x564d5af43921 in calculate() source/main.cpp:35
    #9 0x564d5af4426e in main source/main.cpp:18
    #10 0x7f2f1ba7609a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 8 byte(s) in 1 object(s) allocated from:
    #0 0x7f2f1d3c0ef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x564d5afd5746 in pseudo_nc::pseudo_nc() source/module_cell/pseudo_nc.cpp:19
    #2 0x564d5afc837b in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:4
    #3 0x564d5afcfeef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #4 0x564d5b0191c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #5 0x564d5bc33228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #6 0x564d5bbf530c in Driver::atomic_world() source/driver.cpp:85
    #7 0x564d5bbf84c4 in Driver::init() source/driver.cpp:27
    #8 0x564d5af43921 in calculate() source/main.cpp:35
    #9 0x564d5af4426e in main source/main.cpp:18
    #10 0x7f2f1ba7609a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 8 byte(s) in 1 object(s) allocated from:
    #0 0x7f2f1d3c0ef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x564d5afd57a4 in pseudo_nc::pseudo_nc() source/module_cell/pseudo_nc.cpp:21
    #2 0x564d5afc837b in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:4
    #3 0x564d5afcfeef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #4 0x564d5b0191c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #5 0x564d5bc33228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #6 0x564d5bbf530c in Driver::atomic_world() source/driver.cpp:85
    #7 0x564d5bbf84c4 in Driver::init() source/driver.cpp:27
    #8 0x564d5af43921 in calculate() source/main.cpp:35
    #9 0x564d5af4426e in main source/main.cpp:18
    #10 0x7f2f1ba7609a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 8 byte(s) in 1 object(s) allocated from:
    #0 0x7f2f1d3c0ef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x564d5afd5775 in pseudo_nc::pseudo_nc() source/module_cell/pseudo_nc.cpp:20
    #2 0x564d5afc837b in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:4
    #3 0x564d5afcfeef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #4 0x564d5b0191c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #5 0x564d5bc33228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #6 0x564d5bbf530c in Driver::atomic_world() source/driver.cpp:85
    #7 0x564d5bbf84c4 in Driver::init() source/driver.cpp:27
    #8 0x564d5af43921 in calculate() source/main.cpp:35
    #9 0x564d5af4426e in main source/main.cpp:18
    #10 0x7f2f1ba7609a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 8 byte(s) in 1 object(s) allocated from:
    #0 0x7f2f1d3c0ef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x564d5afd566e in pseudo_nc::pseudo_nc() source/module_cell/pseudo_nc.cpp:10
    #2 0x564d5afc837b in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:4
    #3 0x564d5afcfeef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #4 0x564d5b0191c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #5 0x564d5bc33228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #6 0x564d5bbf530c in Driver::atomic_world() source/driver.cpp:85
    #7 0x564d5bbf84c4 in Driver::init() source/driver.cpp:27
    #8 0x564d5af43921 in calculate() source/main.cpp:35
    #9 0x564d5af4426e in main source/main.cpp:18
    #10 0x7f2f1ba7609a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 8 byte(s) in 1 object(s) allocated from:
    #0 0x7f2f1d3c0ef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x564d5afd5610 in pseudo_nc::pseudo_nc() source/module_cell/pseudo_nc.cpp:8
    #2 0x564d5afc837b in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:4
    #3 0x564d5afcfeef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #4 0x564d5b0191c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #5 0x564d5bc33228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #6 0x564d5bbf530c in Driver::atomic_world() source/driver.cpp:85
    #7 0x564d5bbf84c4 in Driver::init() source/driver.cpp:27
    #8 0x564d5af43921 in calculate() source/main.cpp:35
    #9 0x564d5af4426e in main source/main.cpp:18
    #10 0x7f2f1ba7609a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 4 byte(s) in 1 object(s) allocated from:
    #0 0x7f2f1d3c0ef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x564d5afd5802 in pseudo_nc::pseudo_nc() source/module_cell/pseudo_nc.cpp:25
    #2 0x564d5afc837b in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:4
    #3 0x564d5afcfeef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #4 0x564d5b0191c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #5 0x564d5bc33228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #6 0x564d5bbf530c in Driver::atomic_world() source/driver.cpp:85
    #7 0x564d5bbf84c4 in Driver::init() source/driver.cpp:27
    #8 0x564d5af43921 in calculate() source/main.cpp:35
    #9 0x564d5af4426e in main source/main.cpp:18
    #10 0x7f2f1ba7609a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 4 byte(s) in 1 object(s) allocated from:
    #0 0x7f2f1d3c0ef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x564d5afd569d in pseudo_nc::pseudo_nc() source/module_cell/pseudo_nc.cpp:11
    #2 0x564d5afc837b in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:4
    #3 0x564d5afcfeef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #4 0x564d5b0191c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #5 0x564d5bc33228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #6 0x564d5bbf530c in Driver::atomic_world() source/driver.cpp:85
    #7 0x564d5bbf84c4 in Driver::init() source/driver.cpp:27
    #8 0x564d5af43921 in calculate() source/main.cpp:35
    #9 0x564d5af4426e in main source/main.cpp:18
    #10 0x7f2f1ba7609a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 4 byte(s) in 1 object(s) allocated from:
    #0 0x7f2f1d3c0ef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x564d5afd55c2 in pseudo_nc::pseudo_nc() source/module_cell/pseudo_nc.cpp:7
    #2 0x564d5afc837b in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:4
    #3 0x564d5afcfeef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #4 0x564d5b0191c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #5 0x564d5bc33228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #6 0x564d5bbf530c in Driver::atomic_world() source/driver.cpp:85
    #7 0x564d5bbf84c4 in Driver::init() source/driver.cpp:27
    #8 0x564d5af43921 in calculate() source/main.cpp:35
    #9 0x564d5af4426e in main source/main.cpp:18
    #10 0x7f2f1ba7609a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

SUMMARY: AddressSanitizer: 128 byte(s) leaked in 13 allocation(s).
```

## Test case 101_PW_OU_pseudopots

### On process id asan.2560

```bash

=================================================================
==2560==ERROR: LeakSanitizer: detected memory leaks

Direct leak of 20736 byte(s) in 6 object(s) allocated from:
    #0 0x7fe60499aef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x55bf69bc3e57 in Symmetry::rho_symmetry(double*, int const&, int const&, int const&) source/src_pw/symmetry.cpp:1440
    #2 0x55bf69befd7b in Symmetry_rho::psymm(double*) const source/src_pw/symmetry_rho.cpp:40
    #3 0x55bf69bf0170 in Symmetry_rho::begin(int const&) const source/src_pw/symmetry_rho.cpp:21
    #4 0x55bf69ac737c in Electrons::self_consistent(int const&) source/src_pw/electrons.cpp:236
    #5 0x55bf6973103c in Ions::opt_ions_pw() source/src_ions/ions.cpp:131
    #6 0x55bf69722b21 in Cell_PW::opt_cells_pw() source/src_ions/Cell_PW.cpp:78
    #7 0x55bf69fe2f7a in Run_pw::plane_wave_line() source/run_pw.cpp:104
    #8 0x55bf69fa430c in Driver::atomic_world() source/driver.cpp:85
    #9 0x55bf69fa74c4 in Driver::init() source/driver.cpp:27
    #10 0x55bf692f2921 in calculate() source/main.cpp:35
    #11 0x55bf692f326e in main source/main.cpp:18
    #12 0x7fe60305009a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 3456 byte(s) in 1 object(s) allocated from:
    #0 0x7fe60499aef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x55bf69bc3e57 in Symmetry::rho_symmetry(double*, int const&, int const&, int const&) source/src_pw/symmetry.cpp:1440
    #2 0x55bf69befd7b in Symmetry_rho::psymm(double*) const source/src_pw/symmetry_rho.cpp:40
    #3 0x55bf69bf0170 in Symmetry_rho::begin(int const&) const source/src_pw/symmetry_rho.cpp:21
    #4 0x55bf69ac6c90 in Electrons::self_consistent(int const&) source/src_pw/electrons.cpp:130
    #5 0x55bf6973103c in Ions::opt_ions_pw() source/src_ions/ions.cpp:131
    #6 0x55bf69722b21 in Cell_PW::opt_cells_pw() source/src_ions/Cell_PW.cpp:78
    #7 0x55bf69fe2f7a in Run_pw::plane_wave_line() source/run_pw.cpp:104
    #8 0x55bf69fa430c in Driver::atomic_world() source/driver.cpp:85
    #9 0x55bf69fa74c4 in Driver::init() source/driver.cpp:27
    #10 0x55bf692f2921 in calculate() source/main.cpp:35
    #11 0x55bf692f326e in main source/main.cpp:18
    #12 0x7fe60305009a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 1200 byte(s) in 1 object(s) allocated from:
    #0 0x7fe60499aef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x55bf69aee0ed in Forces::cal_force_ew(matrix&) source/src_pw/forces.cpp:487
    #2 0x55bf69af40e9 in Forces::init(matrix&) source/src_pw/forces.cpp:31
    #3 0x55bf6972bca7 in Ions::force_stress(int const&, int&, int&) source/src_ions/ions.cpp:259
    #4 0x55bf6973248d in Ions::opt_ions_pw() source/src_ions/ions.cpp:197
    #5 0x55bf69722b21 in Cell_PW::opt_cells_pw() source/src_ions/Cell_PW.cpp:78
    #6 0x55bf69fe2f7a in Run_pw::plane_wave_line() source/run_pw.cpp:104
    #7 0x55bf69fa430c in Driver::atomic_world() source/driver.cpp:85
    #8 0x55bf69fa74c4 in Driver::init() source/driver.cpp:27
    #9 0x55bf692f2921 in calculate() source/main.cpp:35
    #10 0x55bf692f326e in main source/main.cpp:18
    #11 0x7fe60305009a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 400 byte(s) in 1 object(s) allocated from:
    #0 0x7fe60499aef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x55bf69aee16c in Forces::cal_force_ew(matrix&) source/src_pw/forces.cpp:488
    #2 0x55bf69af40e9 in Forces::init(matrix&) source/src_pw/forces.cpp:31
    #3 0x55bf6972bca7 in Ions::force_stress(int const&, int&, int&) source/src_ions/ions.cpp:259
    #4 0x55bf6973248d in Ions::opt_ions_pw() source/src_ions/ions.cpp:197
    #5 0x55bf69722b21 in Cell_PW::opt_cells_pw() source/src_ions/Cell_PW.cpp:78
    #6 0x55bf69fe2f7a in Run_pw::plane_wave_line() source/run_pw.cpp:104
    #7 0x55bf69fa430c in Driver::atomic_world() source/driver.cpp:85
    #8 0x55bf69fa74c4 in Driver::init() source/driver.cpp:27
    #9 0x55bf692f2921 in calculate() source/main.cpp:35
    #10 0x55bf692f326e in main source/main.cpp:18
    #11 0x7fe60305009a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 200 byte(s) in 1 object(s) allocated from:
    #0 0x7fe60499aef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x55bf69aee1ae in Forces::cal_force_ew(matrix&) source/src_pw/forces.cpp:490
    #2 0x55bf69af40e9 in Forces::init(matrix&) source/src_pw/forces.cpp:31
    #3 0x55bf6972bca7 in Ions::force_stress(int const&, int&, int&) source/src_ions/ions.cpp:259
    #4 0x55bf6973248d in Ions::opt_ions_pw() source/src_ions/ions.cpp:197
    #5 0x55bf69722b21 in Cell_PW::opt_cells_pw() source/src_ions/Cell_PW.cpp:78
    #6 0x55bf69fe2f7a in Run_pw::plane_wave_line() source/run_pw.cpp:104
    #7 0x55bf69fa430c in Driver::atomic_world() source/driver.cpp:85
    #8 0x55bf69fa74c4 in Driver::init() source/driver.cpp:27
    #9 0x55bf692f2921 in calculate() source/main.cpp:35
    #10 0x55bf692f326e in main source/main.cpp:18
    #11 0x7fe60305009a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 8 byte(s) in 1 object(s) allocated from:
    #0 0x7fe604999330 in __interceptor_malloc (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xe9330)
    #1 0x7fe6036c3cb6  (/usr/lib/x86_64-linux-gnu/libmpich.so.12+0x161cb6)

Direct leak of 8 byte(s) in 1 object(s) allocated from:
    #0 0x7fe604999330 in __interceptor_malloc (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xe9330)
    #1 0x7fe6036c3cd2  (/usr/lib/x86_64-linux-gnu/libmpich.so.12+0x161cd2)

Direct leak of 1 byte(s) in 1 object(s) allocated from:
    #0 0x7fe60499aef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x55bf69a8bb6b in Charge_Extra::allocate_ions() source/src_pw/charge_extra.cpp:114
    #2 0x55bf6972f7f5 in Ions::opt_ions_pw() source/src_ions/ions.cpp:37
    #3 0x55bf69722b21 in Cell_PW::opt_cells_pw() source/src_ions/Cell_PW.cpp:78
    #4 0x55bf69fe2f7a in Run_pw::plane_wave_line() source/run_pw.cpp:104
    #5 0x55bf69fa430c in Driver::atomic_world() source/driver.cpp:85
    #6 0x55bf69fa74c4 in Driver::init() source/driver.cpp:27
    #7 0x55bf692f2921 in calculate() source/main.cpp:35
    #8 0x55bf692f326e in main source/main.cpp:18
    #9 0x7fe60305009a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

SUMMARY: AddressSanitizer: 26009 byte(s) leaked in 13 allocation(s).
```

### On process id asan.2561

```bash

=================================================================
==2561==ERROR: LeakSanitizer: detected memory leaks

Direct leak of 40 byte(s) in 1 object(s) allocated from:
    #0 0x7f4b0bad8ef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x55826e7b34bd in pseudo_nc::pseudo_nc() source/module_cell/pseudo_nc.cpp:6
    #2 0x55826e7a637b in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:4
    #3 0x55826e7adeef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #4 0x55826e7f71c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #5 0x55826f411228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #6 0x55826f3d330c in Driver::atomic_world() source/driver.cpp:85
    #7 0x55826f3d64c4 in Driver::init() source/driver.cpp:27
    #8 0x55826e721921 in calculate() source/main.cpp:35
    #9 0x55826e72226e in main source/main.cpp:18
    #10 0x7f4b0a18e09a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 12 byte(s) in 1 object(s) allocated from:
    #0 0x7f4b0bad8ef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x55826e7a64bc in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:6
    #2 0x55826e7adeef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #3 0x55826e7f71c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #4 0x55826f411228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #5 0x55826f3d330c in Driver::atomic_world() source/driver.cpp:85
    #6 0x55826f3d64c4 in Driver::init() source/driver.cpp:27
    #7 0x55826e721921 in calculate() source/main.cpp:35
    #8 0x55826e72226e in main source/main.cpp:18
    #9 0x7f4b0a18e09a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 8 byte(s) in 1 object(s) allocated from:
    #0 0x7f4b0bad8ef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x55826e7b363f in pseudo_nc::pseudo_nc() source/module_cell/pseudo_nc.cpp:9
    #2 0x55826e7a637b in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:4
    #3 0x55826e7adeef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #4 0x55826e7f71c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #5 0x55826f411228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #6 0x55826f3d330c in Driver::atomic_world() source/driver.cpp:85
    #7 0x55826f3d64c4 in Driver::init() source/driver.cpp:27
    #8 0x55826e721921 in calculate() source/main.cpp:35
    #9 0x55826e72226e in main source/main.cpp:18
    #10 0x7f4b0a18e09a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 8 byte(s) in 1 object(s) allocated from:
    #0 0x7f4b0bad8ef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x55826e7b37d3 in pseudo_nc::pseudo_nc() source/module_cell/pseudo_nc.cpp:22
    #2 0x55826e7a637b in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:4
    #3 0x55826e7adeef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #4 0x55826e7f71c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #5 0x55826f411228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #6 0x55826f3d330c in Driver::atomic_world() source/driver.cpp:85
    #7 0x55826f3d64c4 in Driver::init() source/driver.cpp:27
    #8 0x55826e721921 in calculate() source/main.cpp:35
    #9 0x55826e72226e in main source/main.cpp:18
    #10 0x7f4b0a18e09a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 8 byte(s) in 1 object(s) allocated from:
    #0 0x7f4b0bad8ef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x55826e7b3775 in pseudo_nc::pseudo_nc() source/module_cell/pseudo_nc.cpp:20
    #2 0x55826e7a637b in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:4
    #3 0x55826e7adeef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #4 0x55826e7f71c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #5 0x55826f411228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #6 0x55826f3d330c in Driver::atomic_world() source/driver.cpp:85
    #7 0x55826f3d64c4 in Driver::init() source/driver.cpp:27
    #8 0x55826e721921 in calculate() source/main.cpp:35
    #9 0x55826e72226e in main source/main.cpp:18
    #10 0x7f4b0a18e09a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 8 byte(s) in 1 object(s) allocated from:
    #0 0x7f4b0bad8ef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x55826e7b3746 in pseudo_nc::pseudo_nc() source/module_cell/pseudo_nc.cpp:19
    #2 0x55826e7a637b in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:4
    #3 0x55826e7adeef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #4 0x55826e7f71c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #5 0x55826f411228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #6 0x55826f3d330c in Driver::atomic_world() source/driver.cpp:85
    #7 0x55826f3d64c4 in Driver::init() source/driver.cpp:27
    #8 0x55826e721921 in calculate() source/main.cpp:35
    #9 0x55826e72226e in main source/main.cpp:18
    #10 0x7f4b0a18e09a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 8 byte(s) in 1 object(s) allocated from:
    #0 0x7f4b0bad8ef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x55826e7b366e in pseudo_nc::pseudo_nc() source/module_cell/pseudo_nc.cpp:10
    #2 0x55826e7a637b in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:4
    #3 0x55826e7adeef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #4 0x55826e7f71c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #5 0x55826f411228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #6 0x55826f3d330c in Driver::atomic_world() source/driver.cpp:85
    #7 0x55826f3d64c4 in Driver::init() source/driver.cpp:27
    #8 0x55826e721921 in calculate() source/main.cpp:35
    #9 0x55826e72226e in main source/main.cpp:18
    #10 0x7f4b0a18e09a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 8 byte(s) in 1 object(s) allocated from:
    #0 0x7f4b0bad8ef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x55826e7b37a4 in pseudo_nc::pseudo_nc() source/module_cell/pseudo_nc.cpp:21
    #2 0x55826e7a637b in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:4
    #3 0x55826e7adeef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #4 0x55826e7f71c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #5 0x55826f411228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #6 0x55826f3d330c in Driver::atomic_world() source/driver.cpp:85
    #7 0x55826f3d64c4 in Driver::init() source/driver.cpp:27
    #8 0x55826e721921 in calculate() source/main.cpp:35
    #9 0x55826e72226e in main source/main.cpp:18
    #10 0x7f4b0a18e09a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 8 byte(s) in 1 object(s) allocated from:
    #0 0x7f4b0bad8ef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x55826e7b370a in pseudo_nc::pseudo_nc() source/module_cell/pseudo_nc.cpp:16
    #2 0x55826e7a637b in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:4
    #3 0x55826e7adeef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #4 0x55826e7f71c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #5 0x55826f411228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #6 0x55826f3d330c in Driver::atomic_world() source/driver.cpp:85
    #7 0x55826f3d64c4 in Driver::init() source/driver.cpp:27
    #8 0x55826e721921 in calculate() source/main.cpp:35
    #9 0x55826e72226e in main source/main.cpp:18
    #10 0x7f4b0a18e09a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 8 byte(s) in 1 object(s) allocated from:
    #0 0x7f4b0bad8ef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x55826e7b3610 in pseudo_nc::pseudo_nc() source/module_cell/pseudo_nc.cpp:8
    #2 0x55826e7a637b in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:4
    #3 0x55826e7adeef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #4 0x55826e7f71c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #5 0x55826f411228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #6 0x55826f3d330c in Driver::atomic_world() source/driver.cpp:85
    #7 0x55826f3d64c4 in Driver::init() source/driver.cpp:27
    #8 0x55826e721921 in calculate() source/main.cpp:35
    #9 0x55826e72226e in main source/main.cpp:18
    #10 0x7f4b0a18e09a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 4 byte(s) in 1 object(s) allocated from:
    #0 0x7f4b0bad8ef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x55826e7b35c2 in pseudo_nc::pseudo_nc() source/module_cell/pseudo_nc.cpp:7
    #2 0x55826e7a637b in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:4
    #3 0x55826e7adeef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #4 0x55826e7f71c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #5 0x55826f411228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #6 0x55826f3d330c in Driver::atomic_world() source/driver.cpp:85
    #7 0x55826f3d64c4 in Driver::init() source/driver.cpp:27
    #8 0x55826e721921 in calculate() source/main.cpp:35
    #9 0x55826e72226e in main source/main.cpp:18
    #10 0x7f4b0a18e09a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 4 byte(s) in 1 object(s) allocated from:
    #0 0x7f4b0bad8ef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x55826e7b3802 in pseudo_nc::pseudo_nc() source/module_cell/pseudo_nc.cpp:25
    #2 0x55826e7a637b in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:4
    #3 0x55826e7adeef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #4 0x55826e7f71c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #5 0x55826f411228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #6 0x55826f3d330c in Driver::atomic_world() source/driver.cpp:85
    #7 0x55826f3d64c4 in Driver::init() source/driver.cpp:27
    #8 0x55826e721921 in calculate() source/main.cpp:35
    #9 0x55826e72226e in main source/main.cpp:18
    #10 0x7f4b0a18e09a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 4 byte(s) in 1 object(s) allocated from:
    #0 0x7f4b0bad8ef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x55826e7b369d in pseudo_nc::pseudo_nc() source/module_cell/pseudo_nc.cpp:11
    #2 0x55826e7a637b in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:4
    #3 0x55826e7adeef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #4 0x55826e7f71c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #5 0x55826f411228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #6 0x55826f3d330c in Driver::atomic_world() source/driver.cpp:85
    #7 0x55826f3d64c4 in Driver::init() source/driver.cpp:27
    #8 0x55826e721921 in calculate() source/main.cpp:35
    #9 0x55826e72226e in main source/main.cpp:18
    #10 0x7f4b0a18e09a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 1 byte(s) in 1 object(s) allocated from:
    #0 0x7f4b0bad8ef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x55826eebab6b in Charge_Extra::allocate_ions() source/src_pw/charge_extra.cpp:114
    #2 0x55826eb5e7f5 in Ions::opt_ions_pw() source/src_ions/ions.cpp:37
    #3 0x55826eb51b21 in Cell_PW::opt_cells_pw() source/src_ions/Cell_PW.cpp:78
    #4 0x55826f411f7a in Run_pw::plane_wave_line() source/run_pw.cpp:104
    #5 0x55826f3d330c in Driver::atomic_world() source/driver.cpp:85
    #6 0x55826f3d64c4 in Driver::init() source/driver.cpp:27
    #7 0x55826e721921 in calculate() source/main.cpp:35
    #8 0x55826e72226e in main source/main.cpp:18
    #9 0x7f4b0a18e09a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

SUMMARY: AddressSanitizer: 129 byte(s) leaked in 14 allocation(s).
```

## Test case 101_PW_upf201_pseudopots

### On process id asan.2694

```bash

=================================================================
==2694==ERROR: LeakSanitizer: detected memory leaks

Direct leak of 20736 byte(s) in 6 object(s) allocated from:
    #0 0x7f2bbb059ef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x5604cb156e57 in Symmetry::rho_symmetry(double*, int const&, int const&, int const&) source/src_pw/symmetry.cpp:1440
    #2 0x5604cb182d7b in Symmetry_rho::psymm(double*) const source/src_pw/symmetry_rho.cpp:40
    #3 0x5604cb183170 in Symmetry_rho::begin(int const&) const source/src_pw/symmetry_rho.cpp:21
    #4 0x5604cb05a37c in Electrons::self_consistent(int const&) source/src_pw/electrons.cpp:236
    #5 0x5604cacc403c in Ions::opt_ions_pw() source/src_ions/ions.cpp:131
    #6 0x5604cacb5b21 in Cell_PW::opt_cells_pw() source/src_ions/Cell_PW.cpp:78
    #7 0x5604cb575f7a in Run_pw::plane_wave_line() source/run_pw.cpp:104
    #8 0x5604cb53730c in Driver::atomic_world() source/driver.cpp:85
    #9 0x5604cb53a4c4 in Driver::init() source/driver.cpp:27
    #10 0x5604ca885921 in calculate() source/main.cpp:35
    #11 0x5604ca88626e in main source/main.cpp:18
    #12 0x7f2bb970f09a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 3456 byte(s) in 1 object(s) allocated from:
    #0 0x7f2bbb059ef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x5604cb156e57 in Symmetry::rho_symmetry(double*, int const&, int const&, int const&) source/src_pw/symmetry.cpp:1440
    #2 0x5604cb182d7b in Symmetry_rho::psymm(double*) const source/src_pw/symmetry_rho.cpp:40
    #3 0x5604cb183170 in Symmetry_rho::begin(int const&) const source/src_pw/symmetry_rho.cpp:21
    #4 0x5604cb059c90 in Electrons::self_consistent(int const&) source/src_pw/electrons.cpp:130
    #5 0x5604cacc403c in Ions::opt_ions_pw() source/src_ions/ions.cpp:131
    #6 0x5604cacb5b21 in Cell_PW::opt_cells_pw() source/src_ions/Cell_PW.cpp:78
    #7 0x5604cb575f7a in Run_pw::plane_wave_line() source/run_pw.cpp:104
    #8 0x5604cb53730c in Driver::atomic_world() source/driver.cpp:85
    #9 0x5604cb53a4c4 in Driver::init() source/driver.cpp:27
    #10 0x5604ca885921 in calculate() source/main.cpp:35
    #11 0x5604ca88626e in main source/main.cpp:18
    #12 0x7f2bb970f09a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 8 byte(s) in 1 object(s) allocated from:
    #0 0x7f2bbb058330 in __interceptor_malloc (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xe9330)
    #1 0x7f2bb9d82cd2  (/usr/lib/x86_64-linux-gnu/libmpich.so.12+0x161cd2)

Direct leak of 8 byte(s) in 1 object(s) allocated from:
    #0 0x7f2bbb058330 in __interceptor_malloc (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xe9330)
    #1 0x7f2bb9d82cb6  (/usr/lib/x86_64-linux-gnu/libmpich.so.12+0x161cb6)

SUMMARY: AddressSanitizer: 24208 byte(s) leaked in 9 allocation(s).
```

### On process id asan.2695

```bash

=================================================================
==2695==ERROR: LeakSanitizer: detected memory leaks

Direct leak of 40 byte(s) in 1 object(s) allocated from:
    #0 0x7f1cc00e6ef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x562c08c714bd in pseudo_nc::pseudo_nc() source/module_cell/pseudo_nc.cpp:6
    #2 0x562c08c6437b in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:4
    #3 0x562c08c6beef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #4 0x562c08cb51c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #5 0x562c098cf228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #6 0x562c0989130c in Driver::atomic_world() source/driver.cpp:85
    #7 0x562c098944c4 in Driver::init() source/driver.cpp:27
    #8 0x562c08bdf921 in calculate() source/main.cpp:35
    #9 0x562c08be026e in main source/main.cpp:18
    #10 0x7f1cbe79c09a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 12 byte(s) in 1 object(s) allocated from:
    #0 0x7f1cc00e6ef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x562c08c644bc in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:6
    #2 0x562c08c6beef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #3 0x562c08cb51c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #4 0x562c098cf228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #5 0x562c0989130c in Driver::atomic_world() source/driver.cpp:85
    #6 0x562c098944c4 in Driver::init() source/driver.cpp:27
    #7 0x562c08bdf921 in calculate() source/main.cpp:35
    #8 0x562c08be026e in main source/main.cpp:18
    #9 0x7f1cbe79c09a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 8 byte(s) in 1 object(s) allocated from:
    #0 0x7f1cc00e6ef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x562c08c7163f in pseudo_nc::pseudo_nc() source/module_cell/pseudo_nc.cpp:9
    #2 0x562c08c6437b in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:4
    #3 0x562c08c6beef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #4 0x562c08cb51c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #5 0x562c098cf228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #6 0x562c0989130c in Driver::atomic_world() source/driver.cpp:85
    #7 0x562c098944c4 in Driver::init() source/driver.cpp:27
    #8 0x562c08bdf921 in calculate() source/main.cpp:35
    #9 0x562c08be026e in main source/main.cpp:18
    #10 0x7f1cbe79c09a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 8 byte(s) in 1 object(s) allocated from:
    #0 0x7f1cc00e6ef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x562c08c717d3 in pseudo_nc::pseudo_nc() source/module_cell/pseudo_nc.cpp:22
    #2 0x562c08c6437b in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:4
    #3 0x562c08c6beef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #4 0x562c08cb51c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #5 0x562c098cf228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #6 0x562c0989130c in Driver::atomic_world() source/driver.cpp:85
    #7 0x562c098944c4 in Driver::init() source/driver.cpp:27
    #8 0x562c08bdf921 in calculate() source/main.cpp:35
    #9 0x562c08be026e in main source/main.cpp:18
    #10 0x7f1cbe79c09a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 8 byte(s) in 1 object(s) allocated from:
    #0 0x7f1cc00e6ef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x562c08c7170a in pseudo_nc::pseudo_nc() source/module_cell/pseudo_nc.cpp:16
    #2 0x562c08c6437b in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:4
    #3 0x562c08c6beef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #4 0x562c08cb51c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #5 0x562c098cf228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #6 0x562c0989130c in Driver::atomic_world() source/driver.cpp:85
    #7 0x562c098944c4 in Driver::init() source/driver.cpp:27
    #8 0x562c08bdf921 in calculate() source/main.cpp:35
    #9 0x562c08be026e in main source/main.cpp:18
    #10 0x7f1cbe79c09a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 8 byte(s) in 1 object(s) allocated from:
    #0 0x7f1cc00e6ef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x562c08c71746 in pseudo_nc::pseudo_nc() source/module_cell/pseudo_nc.cpp:19
    #2 0x562c08c6437b in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:4
    #3 0x562c08c6beef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #4 0x562c08cb51c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #5 0x562c098cf228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #6 0x562c0989130c in Driver::atomic_world() source/driver.cpp:85
    #7 0x562c098944c4 in Driver::init() source/driver.cpp:27
    #8 0x562c08bdf921 in calculate() source/main.cpp:35
    #9 0x562c08be026e in main source/main.cpp:18
    #10 0x7f1cbe79c09a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 8 byte(s) in 1 object(s) allocated from:
    #0 0x7f1cc00e6ef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x562c08c717a4 in pseudo_nc::pseudo_nc() source/module_cell/pseudo_nc.cpp:21
    #2 0x562c08c6437b in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:4
    #3 0x562c08c6beef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #4 0x562c08cb51c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #5 0x562c098cf228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #6 0x562c0989130c in Driver::atomic_world() source/driver.cpp:85
    #7 0x562c098944c4 in Driver::init() source/driver.cpp:27
    #8 0x562c08bdf921 in calculate() source/main.cpp:35
    #9 0x562c08be026e in main source/main.cpp:18
    #10 0x7f1cbe79c09a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 8 byte(s) in 1 object(s) allocated from:
    #0 0x7f1cc00e6ef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x562c08c71775 in pseudo_nc::pseudo_nc() source/module_cell/pseudo_nc.cpp:20
    #2 0x562c08c6437b in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:4
    #3 0x562c08c6beef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #4 0x562c08cb51c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #5 0x562c098cf228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #6 0x562c0989130c in Driver::atomic_world() source/driver.cpp:85
    #7 0x562c098944c4 in Driver::init() source/driver.cpp:27
    #8 0x562c08bdf921 in calculate() source/main.cpp:35
    #9 0x562c08be026e in main source/main.cpp:18
    #10 0x7f1cbe79c09a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 8 byte(s) in 1 object(s) allocated from:
    #0 0x7f1cc00e6ef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x562c08c7166e in pseudo_nc::pseudo_nc() source/module_cell/pseudo_nc.cpp:10
    #2 0x562c08c6437b in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:4
    #3 0x562c08c6beef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #4 0x562c08cb51c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #5 0x562c098cf228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #6 0x562c0989130c in Driver::atomic_world() source/driver.cpp:85
    #7 0x562c098944c4 in Driver::init() source/driver.cpp:27
    #8 0x562c08bdf921 in calculate() source/main.cpp:35
    #9 0x562c08be026e in main source/main.cpp:18
    #10 0x7f1cbe79c09a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 8 byte(s) in 1 object(s) allocated from:
    #0 0x7f1cc00e6ef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x562c08c71610 in pseudo_nc::pseudo_nc() source/module_cell/pseudo_nc.cpp:8
    #2 0x562c08c6437b in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:4
    #3 0x562c08c6beef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #4 0x562c08cb51c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #5 0x562c098cf228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #6 0x562c0989130c in Driver::atomic_world() source/driver.cpp:85
    #7 0x562c098944c4 in Driver::init() source/driver.cpp:27
    #8 0x562c08bdf921 in calculate() source/main.cpp:35
    #9 0x562c08be026e in main source/main.cpp:18
    #10 0x7f1cbe79c09a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 4 byte(s) in 1 object(s) allocated from:
    #0 0x7f1cc00e6ef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x562c08c71802 in pseudo_nc::pseudo_nc() source/module_cell/pseudo_nc.cpp:25
    #2 0x562c08c6437b in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:4
    #3 0x562c08c6beef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #4 0x562c08cb51c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #5 0x562c098cf228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #6 0x562c0989130c in Driver::atomic_world() source/driver.cpp:85
    #7 0x562c098944c4 in Driver::init() source/driver.cpp:27
    #8 0x562c08bdf921 in calculate() source/main.cpp:35
    #9 0x562c08be026e in main source/main.cpp:18
    #10 0x7f1cbe79c09a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 4 byte(s) in 1 object(s) allocated from:
    #0 0x7f1cc00e6ef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x562c08c7169d in pseudo_nc::pseudo_nc() source/module_cell/pseudo_nc.cpp:11
    #2 0x562c08c6437b in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:4
    #3 0x562c08c6beef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #4 0x562c08cb51c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #5 0x562c098cf228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #6 0x562c0989130c in Driver::atomic_world() source/driver.cpp:85
    #7 0x562c098944c4 in Driver::init() source/driver.cpp:27
    #8 0x562c08bdf921 in calculate() source/main.cpp:35
    #9 0x562c08be026e in main source/main.cpp:18
    #10 0x7f1cbe79c09a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 4 byte(s) in 1 object(s) allocated from:
    #0 0x7f1cc00e6ef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x562c08c715c2 in pseudo_nc::pseudo_nc() source/module_cell/pseudo_nc.cpp:7
    #2 0x562c08c6437b in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:4
    #3 0x562c08c6beef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #4 0x562c08cb51c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #5 0x562c098cf228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #6 0x562c0989130c in Driver::atomic_world() source/driver.cpp:85
    #7 0x562c098944c4 in Driver::init() source/driver.cpp:27
    #8 0x562c08bdf921 in calculate() source/main.cpp:35
    #9 0x562c08be026e in main source/main.cpp:18
    #10 0x7f1cbe79c09a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

SUMMARY: AddressSanitizer: 128 byte(s) leaked in 13 allocation(s).
```

## Test case 101_PW_VW_pseudopots

### On process id asan.2781

```bash

=================================================================
==2781==ERROR: LeakSanitizer: detected memory leaks

Direct leak of 20736 byte(s) in 6 object(s) allocated from:
    #0 0x7fd9de2a4ef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x5559db89ce57 in Symmetry::rho_symmetry(double*, int const&, int const&, int const&) source/src_pw/symmetry.cpp:1440
    #2 0x5559db8c8d7b in Symmetry_rho::psymm(double*) const source/src_pw/symmetry_rho.cpp:40
    #3 0x5559db8c9170 in Symmetry_rho::begin(int const&) const source/src_pw/symmetry_rho.cpp:21
    #4 0x5559db7a037c in Electrons::self_consistent(int const&) source/src_pw/electrons.cpp:236
    #5 0x5559db40a03c in Ions::opt_ions_pw() source/src_ions/ions.cpp:131
    #6 0x5559db3fbb21 in Cell_PW::opt_cells_pw() source/src_ions/Cell_PW.cpp:78
    #7 0x5559dbcbbf7a in Run_pw::plane_wave_line() source/run_pw.cpp:104
    #8 0x5559dbc7d30c in Driver::atomic_world() source/driver.cpp:85
    #9 0x5559dbc804c4 in Driver::init() source/driver.cpp:27
    #10 0x5559dafcb921 in calculate() source/main.cpp:35
    #11 0x5559dafcc26e in main source/main.cpp:18
    #12 0x7fd9dc95a09a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 3456 byte(s) in 1 object(s) allocated from:
    #0 0x7fd9de2a4ef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x5559db89ce57 in Symmetry::rho_symmetry(double*, int const&, int const&, int const&) source/src_pw/symmetry.cpp:1440
    #2 0x5559db8c8d7b in Symmetry_rho::psymm(double*) const source/src_pw/symmetry_rho.cpp:40
    #3 0x5559db8c9170 in Symmetry_rho::begin(int const&) const source/src_pw/symmetry_rho.cpp:21
    #4 0x5559db79fc90 in Electrons::self_consistent(int const&) source/src_pw/electrons.cpp:130
    #5 0x5559db40a03c in Ions::opt_ions_pw() source/src_ions/ions.cpp:131
    #6 0x5559db3fbb21 in Cell_PW::opt_cells_pw() source/src_ions/Cell_PW.cpp:78
    #7 0x5559dbcbbf7a in Run_pw::plane_wave_line() source/run_pw.cpp:104
    #8 0x5559dbc7d30c in Driver::atomic_world() source/driver.cpp:85
    #9 0x5559dbc804c4 in Driver::init() source/driver.cpp:27
    #10 0x5559dafcb921 in calculate() source/main.cpp:35
    #11 0x5559dafcc26e in main source/main.cpp:18
    #12 0x7fd9dc95a09a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 8 byte(s) in 1 object(s) allocated from:
    #0 0x7fd9de2a3330 in __interceptor_malloc (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xe9330)
    #1 0x7fd9dcfcdcd2  (/usr/lib/x86_64-linux-gnu/libmpich.so.12+0x161cd2)

Direct leak of 8 byte(s) in 1 object(s) allocated from:
    #0 0x7fd9de2a3330 in __interceptor_malloc (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xe9330)
    #1 0x7fd9dcfcdcb6  (/usr/lib/x86_64-linux-gnu/libmpich.so.12+0x161cb6)

SUMMARY: AddressSanitizer: 24208 byte(s) leaked in 9 allocation(s).
```

### On process id asan.2782

```bash

=================================================================
==2782==ERROR: LeakSanitizer: detected memory leaks

Direct leak of 40 byte(s) in 1 object(s) allocated from:
    #0 0x7ffabf775ef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x5655073694bd in pseudo_nc::pseudo_nc() source/module_cell/pseudo_nc.cpp:6
    #2 0x56550735c37b in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:4
    #3 0x565507363eef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #4 0x5655073ad1c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #5 0x565507fc7228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #6 0x565507f8930c in Driver::atomic_world() source/driver.cpp:85
    #7 0x565507f8c4c4 in Driver::init() source/driver.cpp:27
    #8 0x5655072d7921 in calculate() source/main.cpp:35
    #9 0x5655072d826e in main source/main.cpp:18
    #10 0x7ffabde2b09a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 12 byte(s) in 1 object(s) allocated from:
    #0 0x7ffabf775ef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x56550735c4bc in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:6
    #2 0x565507363eef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #3 0x5655073ad1c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #4 0x565507fc7228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #5 0x565507f8930c in Driver::atomic_world() source/driver.cpp:85
    #6 0x565507f8c4c4 in Driver::init() source/driver.cpp:27
    #7 0x5655072d7921 in calculate() source/main.cpp:35
    #8 0x5655072d826e in main source/main.cpp:18
    #9 0x7ffabde2b09a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 8 byte(s) in 1 object(s) allocated from:
    #0 0x7ffabf775ef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x56550736963f in pseudo_nc::pseudo_nc() source/module_cell/pseudo_nc.cpp:9
    #2 0x56550735c37b in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:4
    #3 0x565507363eef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #4 0x5655073ad1c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #5 0x565507fc7228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #6 0x565507f8930c in Driver::atomic_world() source/driver.cpp:85
    #7 0x565507f8c4c4 in Driver::init() source/driver.cpp:27
    #8 0x5655072d7921 in calculate() source/main.cpp:35
    #9 0x5655072d826e in main source/main.cpp:18
    #10 0x7ffabde2b09a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 8 byte(s) in 1 object(s) allocated from:
    #0 0x7ffabf775ef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x5655073697d3 in pseudo_nc::pseudo_nc() source/module_cell/pseudo_nc.cpp:22
    #2 0x56550735c37b in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:4
    #3 0x565507363eef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #4 0x5655073ad1c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #5 0x565507fc7228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #6 0x565507f8930c in Driver::atomic_world() source/driver.cpp:85
    #7 0x565507f8c4c4 in Driver::init() source/driver.cpp:27
    #8 0x5655072d7921 in calculate() source/main.cpp:35
    #9 0x5655072d826e in main source/main.cpp:18
    #10 0x7ffabde2b09a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 8 byte(s) in 1 object(s) allocated from:
    #0 0x7ffabf775ef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x56550736970a in pseudo_nc::pseudo_nc() source/module_cell/pseudo_nc.cpp:16
    #2 0x56550735c37b in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:4
    #3 0x565507363eef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #4 0x5655073ad1c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #5 0x565507fc7228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #6 0x565507f8930c in Driver::atomic_world() source/driver.cpp:85
    #7 0x565507f8c4c4 in Driver::init() source/driver.cpp:27
    #8 0x5655072d7921 in calculate() source/main.cpp:35
    #9 0x5655072d826e in main source/main.cpp:18
    #10 0x7ffabde2b09a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 8 byte(s) in 1 object(s) allocated from:
    #0 0x7ffabf775ef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x565507369746 in pseudo_nc::pseudo_nc() source/module_cell/pseudo_nc.cpp:19
    #2 0x56550735c37b in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:4
    #3 0x565507363eef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #4 0x5655073ad1c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #5 0x565507fc7228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #6 0x565507f8930c in Driver::atomic_world() source/driver.cpp:85
    #7 0x565507f8c4c4 in Driver::init() source/driver.cpp:27
    #8 0x5655072d7921 in calculate() source/main.cpp:35
    #9 0x5655072d826e in main source/main.cpp:18
    #10 0x7ffabde2b09a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 8 byte(s) in 1 object(s) allocated from:
    #0 0x7ffabf775ef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x5655073697a4 in pseudo_nc::pseudo_nc() source/module_cell/pseudo_nc.cpp:21
    #2 0x56550735c37b in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:4
    #3 0x565507363eef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #4 0x5655073ad1c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #5 0x565507fc7228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #6 0x565507f8930c in Driver::atomic_world() source/driver.cpp:85
    #7 0x565507f8c4c4 in Driver::init() source/driver.cpp:27
    #8 0x5655072d7921 in calculate() source/main.cpp:35
    #9 0x5655072d826e in main source/main.cpp:18
    #10 0x7ffabde2b09a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 8 byte(s) in 1 object(s) allocated from:
    #0 0x7ffabf775ef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x565507369775 in pseudo_nc::pseudo_nc() source/module_cell/pseudo_nc.cpp:20
    #2 0x56550735c37b in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:4
    #3 0x565507363eef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #4 0x5655073ad1c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #5 0x565507fc7228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #6 0x565507f8930c in Driver::atomic_world() source/driver.cpp:85
    #7 0x565507f8c4c4 in Driver::init() source/driver.cpp:27
    #8 0x5655072d7921 in calculate() source/main.cpp:35
    #9 0x5655072d826e in main source/main.cpp:18
    #10 0x7ffabde2b09a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 8 byte(s) in 1 object(s) allocated from:
    #0 0x7ffabf775ef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x56550736966e in pseudo_nc::pseudo_nc() source/module_cell/pseudo_nc.cpp:10
    #2 0x56550735c37b in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:4
    #3 0x565507363eef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #4 0x5655073ad1c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #5 0x565507fc7228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #6 0x565507f8930c in Driver::atomic_world() source/driver.cpp:85
    #7 0x565507f8c4c4 in Driver::init() source/driver.cpp:27
    #8 0x5655072d7921 in calculate() source/main.cpp:35
    #9 0x5655072d826e in main source/main.cpp:18
    #10 0x7ffabde2b09a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 8 byte(s) in 1 object(s) allocated from:
    #0 0x7ffabf775ef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x565507369610 in pseudo_nc::pseudo_nc() source/module_cell/pseudo_nc.cpp:8
    #2 0x56550735c37b in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:4
    #3 0x565507363eef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #4 0x5655073ad1c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #5 0x565507fc7228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #6 0x565507f8930c in Driver::atomic_world() source/driver.cpp:85
    #7 0x565507f8c4c4 in Driver::init() source/driver.cpp:27
    #8 0x5655072d7921 in calculate() source/main.cpp:35
    #9 0x5655072d826e in main source/main.cpp:18
    #10 0x7ffabde2b09a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 4 byte(s) in 1 object(s) allocated from:
    #0 0x7ffabf775ef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x565507369802 in pseudo_nc::pseudo_nc() source/module_cell/pseudo_nc.cpp:25
    #2 0x56550735c37b in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:4
    #3 0x565507363eef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #4 0x5655073ad1c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #5 0x565507fc7228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #6 0x565507f8930c in Driver::atomic_world() source/driver.cpp:85
    #7 0x565507f8c4c4 in Driver::init() source/driver.cpp:27
    #8 0x5655072d7921 in calculate() source/main.cpp:35
    #9 0x5655072d826e in main source/main.cpp:18
    #10 0x7ffabde2b09a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 4 byte(s) in 1 object(s) allocated from:
    #0 0x7ffabf775ef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x56550736969d in pseudo_nc::pseudo_nc() source/module_cell/pseudo_nc.cpp:11
    #2 0x56550735c37b in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:4
    #3 0x565507363eef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #4 0x5655073ad1c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #5 0x565507fc7228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #6 0x565507f8930c in Driver::atomic_world() source/driver.cpp:85
    #7 0x565507f8c4c4 in Driver::init() source/driver.cpp:27
    #8 0x5655072d7921 in calculate() source/main.cpp:35
    #9 0x5655072d826e in main source/main.cpp:18
    #10 0x7ffabde2b09a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

Direct leak of 4 byte(s) in 1 object(s) allocated from:
    #0 0x7ffabf775ef0 in operator new[](unsigned long) (/usr/lib/x86_64-linux-gnu/libasan.so.5+0xeaef0)
    #1 0x5655073695c2 in pseudo_nc::pseudo_nc() source/module_cell/pseudo_nc.cpp:7
    #2 0x56550735c37b in Atom_pseudo::Atom_pseudo() source/module_cell/atom_pseudo.cpp:4
    #3 0x565507363eef in Atom::Atom() source/module_cell/atom_spec.cpp:4
    #4 0x5655073ad1c9 in UnitCell_pseudo::setup_cell(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, output&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_ofstream<char, std::char_traits<char> >&) source/module_cell/unitcell_pseudo.cpp:39
    #5 0x565507fc7228 in Run_pw::plane_wave_line() source/run_pw.cpp:25
    #6 0x565507f8930c in Driver::atomic_world() source/driver.cpp:85
    #7 0x565507f8c4c4 in Driver::init() source/driver.cpp:27
    #8 0x5655072d7921 in calculate() source/main.cpp:35
    #9 0x5655072d826e in main source/main.cpp:18
    #10 0x7ffabde2b09a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2409a)

SUMMARY: AddressSanitizer: 128 byte(s) leaked in 13 allocation(s).
```

