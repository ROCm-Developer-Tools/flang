/*
 * Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
 * See https://llvm.org/LICENSE.txt for license information.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 *
 */

/* 
 * Modifications Copyright (c) 2019 Advanced Micro Devices, Inc. All rights reserved.
 * Notified per clause 4(b) of the license.
 *
 * Support for DNORM intrinsic
 *  Date of Modification: 21st February 2019
 *
 * Support for Bit Sequence Comparsion intrinsic
 *  Month of Modification: May 2019
 *
 * Support for Bit Masking intrinsics.
 *  Month of Modification: May 2019
 *
 * Support for F2008 EXECUTE_COMMAND_LINE intrinsic subroutine.
 *  Month of Modification: July 2019
 *
 * Support for TRAILZ intrinsic.
 *  Month of Modification: July 2019
 *
 * Support for Bit transformational intrinsic iany, iall, iparity.
 *  Month of Modification: July 2019
 *
 * Added support for quad precision
 *  Last modified: Feb 2020
 *
 * Support for real*16 intrinsics
 * Date of Modification: 18th July 2020
 */

/** \file Provides the front-end access to the run time library structure
 *  defined  in rte_rtns.h
 */

#include <string.h>
#include "gbldefs.h"
#include "global.h"
#include "error.h"
#include "rtlRtnsDesc.h"
#include "rtlRtns.h"

/* NOTE: within each section (E.g., NO RTN to END_OF_PFX_F90,
 * END_OF_PFX_F90+1 to ...) the ftnRtlRtns entries must be sorted on the
 * baseNm field.
 */
FtnRteRtn ftnRtlRtns[] = {
    {"NO RTN", "", false, ""},
    {"achara", "", false, ""},
    {"addr_1_dim_1st_elem", "", true, ""},
    {"adjustla", "", false, ""},
    {"adjustra", "", false, ""},
    {"alloca", "", true, "k"},
    {"alloc03a", "", true, ""},
    {"alloc03_chka", "", true, ""},
    {"alloc04a", "", true, ""},
    {"alloc04_chka", "", true, ""},
    {"alloc04_chkma", "", true, ""},
    {"alloc04_chkpa", "", true, ""},
    {"alloc04ma", "", true, ""},
    {"alloc04pa", "", true, ""},
    {"allocated", "", true, "k"},
    {"allocated2", "", true, "k"},
    {"allocated_lhs", "", true, "k"},
    {"allocated_lhs2", "", true, "k"},
    {"amodulev", "", false, ""},
    {"amodulov", "", false, ""},
    {"asn_closure", "", true, ""},
    {"auto_alloc", "", true, ""},
    {"auto_alloc04", "", true, ""},
    {"auto_alloc04m", "", true, ""},
    {"auto_alloc04p", "", true, ""},
    {"auto_allocv", "", false, ""},
    {"auto_calloc", "", true, ""},
    {"auto_calloc04", "", true, ""},
    {"auto_calloc04m", "", true, ""},
    {"auto_calloc04p", "", true, ""},
    {"auto_dealloc", "", true, ""},
    {"auto_deallocm", "", true, ""},
    {"auto_deallocp", "", true, ""},
    /* AOCC begin */
    {"bitcmp", "", false, ""},
    {"bitmask", "", false, ""},
    /* AOCC end */
    {"c_f_procptr", "", false, ""},
    {"c_f_ptr", "", true, ""},
    {"calloc03a", "", true, ""},
    {"calloc04a", "", true, ""},
    {"calloc04ma", "", true, ""},
    {"calloc04pa", "", true, ""},
    {"ceiling", "", false, "k"},
    {"ceilingv", "", false, "k"},
    {"class_obj_size", "", true, ""},
    {"cmd_arg_cnt", "", false, "k"},
    {"cmplx16", "", false, ""},
    {"cmplx32", "", false, ""},
    {"cmplx8", "", false, ""},
    {"conformable", "", false, ""},
    {"conformable_11v", "", true, ""},
    {"conformable_1dv", "", true, ""},
    {"conformable_22v", "", true, ""},
    {"conformable_2dv", "", true, ""},
    {"conformable_33v", "", true, ""},
    {"conformable_3dv", "", true, ""},
    {"conformable_d1v", "", true, ""},
    {"conformable_d2v", "", true, ""},
    {"conformable_d3v", "", true, ""},
    {"conformable_dd", "", true, ""},
    {"conformable_dnv", "", true, ""},
    {"conformable_ndv", "", true, ""},
    {"conformable_nnv", "", true, ""},
    {"contigchk", "", true, ""},
    {"contigerror", "", true, ""},
    {"copy_f77_argl", "", true, ""},
    {"copy_f77_argsl", "", true, ""},
    {"copy_f90_argl", "", true, ""},
    {"copy_proc_desc", "", true, ""},
    {"dble", "", false, ""},
    {"dceiling", "", false, "k"},
    {"dceilingv", "", false, "k"},
    {"dealloca", "", true, ""},
    {"dealloc03a", "", true, ""},
    {"dealloc03ma", "", true, ""},
    {"dealloc03pa", "", true, ""},
    {"dealloc_mbr03a", "", true, ""},
    {"dealloc_mbr03ma", "", true, ""},
    {"dealloc_mbr03pa", "", true, ""},
    {"dealloc_poly03", "", true, ""},
    {"dealloc_poly_mbr03a", "", true, ""},
    {"deallocx", "", true, ""},
    {"dfloor", "", false, "k"},
    {"dfloorv", "", false, "k"},
    {"dmodulev", "", false, ""},
    {"dmodulov", "", false, ""},
    {"errorstop08a_char", "", false, ""},
    {"errorstop08a_int", "", false, ""},
    {"execcmdline", "", false, ""},
    {"exit", "", false, ""},
    {"expon", "", false, "k"},
    {"expond", "", false, "k"},
    {"expondx", "", false, "k"},
    {"exponx", "", false, "k"},
    {"extends_type_of", "", true, "k"},
    {"finalize", "", true, ""},
    {"floor", "", false, "k"},
    {"floorv", "", false, "k"},
    {"frac", "", false, ""},
    {"fracd", "", false, ""},
    {"fracdx", "", false, ""},
    {"fracq", "", false, ""},
    {"fracqx", "", false, ""},
    {"fracx", "", false, ""},
    {"get_cmda", "", false, ""},
    {"get_cmd_arga", "", false, ""},
    {"get_env_vara", "", false, ""},
    {"hypot", "", false, ""},
    {"hypotd", "", false, ""},
    {"i8modulov", "", true, ""},
    {"iachara", "", false, "k"},
    {"ichar", "", false, "k"},
    {"imodulov", "", false, ""},
    {"indexa", "", false, "k"},
    {"init_from_desc", "", true, ""},
    {"init_unl_poly_desc", "", true, ""},
    {"int", "", false, ""},
    {"int1", "", false, ""},
    {"int2", "", false, ""},
    {"int4", "", false, ""},
    {"int8", "", false, ""},
    {"is_contiguous", "", true, ""},
    {"is_iostat_end", "", false, "k"},
    {"is_iostat_eor", "", false, "k"},
    {"kexpondx", "", false, ""},
    {"ksize", "", true, ""},
    {"lb", "", true, "k"},
    {"lb1", "", true, ""},
    {"lb2", "", true, ""},
    {"lb4", "", true, ""},
    {"lb8", "", true, ""},
    {"lba", "", true, "k"},
    {"lba1", "", true, ""},
    {"lba2", "", true, ""},
    {"lba4", "", true, ""},
    {"lba8", "", true, ""},
    {"lbaz", "", true, "k"},
    {"lbaz1", "", true, ""},
    {"lbaz2", "", true, ""},
    {"lbaz4", "", true, ""},
    {"lbaz8", "", true, ""},
    {"lbound", "", false, "k"},
    {"lbound1", "", true, ""},
    {"lbound2", "", true, ""},
    {"lbound4", "", true, ""},
    {"lbound8", "", true, ""},
    {"lbounda", "", false, "k"},
    {"lbounda1", "", false, ""},
    {"lbounda2", "", false, ""},
    {"lbounda4", "", false, ""},
    {"lbounda8", "", false, ""},
    {"lboundaz", "", false, "k"},
    {"lboundaz1", "", false, ""},
    {"lboundaz2", "", false, ""},
    {"lboundaz4", "", false, ""},
    {"lboundaz8", "", false, ""},
    {"lena", "", false, "k"},
    {"lentrima", "", false, "k"},
    {"loc", "", false, ""},
    {"log1", "", false, ""},
    {"log2", "", false, ""},
    {"log4", "", false, ""},
    {"log8", "", false, ""},
    {"matmul_cplx16", "", true, ""},
    {"matmul_cplx16mxv_t", "", true, ""},
    {"matmul_cplx32", "", true, ""},
    {"matmul_cplx8", "", true, ""},
    {"matmul_cplx8mxv_t", "", true, ""},
    {"matmul_int1", "", true, ""},
    {"matmul_int2", "", true, ""},
    {"matmul_int4", "", true, ""},
    {"matmul_int8", "", true, ""},
    {"matmul_log1", "", true, ""},
    {"matmul_log2", "", true, ""},
    {"matmul_log4", "", true, ""},
    {"matmul_log8", "", true, ""},
    {"matmul_real16", "", true, ""},
    {"matmul_real4", "", true, ""},
    {"matmul_real4mxv_t", "", true, ""},
    {"matmul_real8", "", true, ""},
    {"matmul_real8mxv_t", "", true, ""},
    {"max", "", false, "k"},
    {"mcopy1", "", false, ""},
    {"mcopy2", "", false, ""},
    {"mcopy4", "", false, ""},
    {"mcopy8", "", false, ""},
    {"mcopyz16", "", false, ""},
    {"mcopyz4", "", false, ""},
    {"mcopyz8", "", false, ""},
    {"mergec", "", false, ""},
    {"mergecha", "", false, ""},
    {"merged", "", false, ""},
    {"mergedc", "", false, ""},
    {"mergedt", "", false, ""},
    {"mergei", "", false, ""},
    {"mergei1", "", false, ""},
    {"mergei2", "", false, ""},
    {"mergei8", "", false, ""},
    {"mergel", "", false, ""},
    {"mergel1", "", false, ""},
    {"mergel2", "", false, ""},
    {"mergel8", "", false, ""},
    {"mergeq", "", false, ""},
    {"mergeqc", "", false, ""},      // AOCC
    {"merger", "", false, ""},
    {"min", "", false, "k"},
    {"mmul_cmplx32", "", false, ""},
    {"mmul_cmplx16", "", false, ""},
    {"mmul_cmplx8", "", false, ""},
    {"mmul_real4", "", false, ""},
    {"mmul_real8", "", false, ""},
    {"modulov", "", false, ""},
    {"move_alloc", "", true, ""},
    {"mp_bcs_nest", "", false, ""},
    {"mp_ecs_nest", "", false, ""},
    {"mset1", "", false, ""},
    {"mset2", "", false, ""},
    {"mset4", "", false, ""},
    {"mset8", "", false, ""},
    {"msetz16", "", false, ""},
    {"msetz4", "", false, ""},
    {"msetz8", "", false, ""},
    {"mvbits", "", false, ""},
    {"mzero1", "", false, ""},
    {"mzero2", "", false, ""},
    {"mzero4", "", false, ""},
    {"mzero8", "", false, ""},
    {"mzeroz16", "", false, ""},
    {"mzeroz4", "", false, ""},
    {"mzeroz8", "", false, ""},
    {"nadjustl", "", false, ""},
    {"nadjustr", "", false, ""},
    {"name", "", false, ""},
    {"nearest", "", false, ""},
    {"nearestd", "", false, ""},
    {"nearestdx", "", false, ""},
    {"nearestx", "", false, ""},
    //AOCC Begin
    {"nearestq", "", false, ""},
    {"nearestqx", "", false, ""},
    //AOCC End
    {"nlena", "", true, ""},
    {"nlentrim", "", false, ""},
    // AOCC Begin
    // Enable i8 descriptor to access the dims in library
    {"norm2_real4", "", true, ""},
    {"norm2_real4_dim", "", true, ""},
    {"norm2_real8", "", true, ""},
    {"norm2_real8_dim", "", true, ""},
    // AOCC End
    {"nrepeat", "", false, ""},
    {"nscan", "", false, "k"},
    {"nstr_copy", "", false, ""},
    {"nstr_copy_klen", "", false, ""},
    {"nstr_index", "", false, ""},
    {"nstr_index_klen", "", false, ""},
    {"nstrcmp", "", false, ""},
    {"nstrcmp_klen", "", false, ""},
    {"ntrim", "", false, ""},
    {"nverify", "", false, "k"},
    {"pausea", "", false, ""},
    {"poly_asn", "", true, ""},
    {"poly_asn_dest_intrin", "", true, ""},
    {"poly_asn_src_intrin", "", true, ""},
    {"poly_conform_types", "", true, ""},
    {"poly_element_addr", "", true, "k"},
    {"poly_element_addr1", "", true, "k"},
    {"poly_element_addr2", "", true, "k"},
    {"poly_element_addr3", "", true, "k"},
    {"present", "", false, "k"},
    {"present_ptr", "", false, "k"},
    {"presentca", "", false, "k"},
    {"ptr_alloca", "", false, ""},
    {"ptr_alloc03a", "", true, ""},
    {"ptr_alloc04a", "", true, ""},
    {"ptr_alloc04ma", "", false, ""},
    {"ptr_alloc04pa", "", false, ""},
    {"ptr_calloc03a", "", true, ""},
    {"ptr_calloc04a", "", true, ""},
    {"ptr_calloc04ma", "", false, ""},
    {"ptr_calloc04pa", "", false, ""},
    {"ptr_src_alloc03a", "", true, ""},
    {"ptr_src_alloc04a", "", true, ""},
    {"ptr_src_alloc04ma", "", true, ""},
    {"ptr_src_alloc04pa", "", true, ""},
    {"ptr_src_calloc03a", "", true, ""},
    {"ptr_src_calloc04a", "", true, ""},
    {"ptr_src_calloc04ma", "", true, ""},
    {"ptr_src_calloc04pa", "", true, ""},
    {"ptrchk", "", false, ""},
    {"ptrcp", "", false, ""},
    {"real", "", false, ""},
    {"real32", "", false, ""},
    {"real16", "", false, ""},
    {"real4", "", false, ""},
    {"real8", "", false, ""},
    {"repeata", "", false, ""},
    {"rrspacing", "", false, ""},
    {"rrspacingd", "", false, ""},
    {"rrspacingdx", "", false, ""},
    {"rrspacingq", "", false, ""},
    {"rrspacingqx", "", false, ""},
    {"rrspacingx", "", false, ""},
    {"rtn_name", "", false, ""},
    {"same_intrin_type_as", "", true, "k"},
    {"same_type_as", "", true, "k"},
    {"scale", "", false, ""},
    {"scaled", "", false, ""},
    {"scaledx", "", false, ""},
    //AOCC Begin
    {"scaleq", "", false, ""},
    {"scaleqx", "", false, ""},
    //AOCC End
    {"scalex", "", false, ""},
    {"scana", "", false, "k"},
    {"sect", "", true, ""},
    {"sect1", "", true, ""},
    {"sect1v", "", true, ""},
    {"sect2", "", true, ""},
    {"sect2v", "", true, ""},
    {"sect3", "", true, ""},
    {"sect3v", "", true, ""},
    {"sel_char_kinda", "", true, "k"},
    {"sel_int_kind", "", true, "k"},
    {"sel_real_kind", "", true, "k"},
    {"set_intrin_type", "", true, ""},
    {"set_type", "", true, ""},
    {"setexp", "", false, ""},
    {"setexpd", "", false, ""},
    {"setexpdx", "", false, ""},
    {"setexpq", "", false, ""},
    {"setexpqx", "", false, ""},
    {"setexpx", "", false, ""},
    {"shape", "", true, "k"},
    {"shape1", "", true, ""},
    {"shape2", "", true, ""},
    {"shape4", "", true, ""},
    {"shape8", "", true, ""},
    {"show", "", false, ""},
    {"size", "", true, "k"},
    {"spacing", "", false, ""},
    {"spacingd", "", false, ""},
    {"spacingdx", "", false, ""},
    {"spacingq", "", false, ""},
    {"spacingqx", "", false, ""},
    {"spacingx", "", false, ""},
    {"stopa", "", false, ""},
    {"stop08a", "", false, ""},
    {"str_copy", "", false, ""},
    {"str_copy_klen", "", false, ""},
    {"str_cpy1", "", false, ""},
    {"str_free", "", false, ""},
    {"str_index", "", false, ""},
    {"str_index_klen", "", false, ""},
    {"str_malloc", "", false, ""},
    {"str_malloc_klen", "", false, ""},
    {"strcmp", "", false, ""},
    {"strcmp_klen", "", false, ""},
    {"subchk", "", false, ""},
    {"subchk64", "", false, ""},
    {"tmp_desc", "", true, ""},
    {"template", "", true, ""},
    {"template1", "", true, ""},
    {"template1v", "", true, ""},
    {"template2", "", true, ""},
    {"template2v", "", true, ""},
    {"template3", "", true, ""},
    {"template3v", "", true, ""},
    {"test_and_set_type", "", true, ""},
    {"trima", "", false, ""},
    {"ub", "", true, "k"},
    {"ub1", "", true, ""},
    {"ub2", "", true, ""},
    {"ub4", "", true, ""},
    {"ub8", "", true, ""},
    {"uba", "", true, "k"},
    {"uba1", "", true, ""},
    {"uba2", "", true, ""},
    {"uba4", "", true, ""},
    {"uba8", "", true, ""},
    {"ubaz", "", true, "k"},
    {"ubaz1", "", true, ""},
    {"ubaz2", "", true, ""},
    {"ubaz4", "", true, ""},
    {"ubaz8", "", true, ""},
    {"ubound", "", false, "k"},
    {"ubound1", "", true, ""},
    {"ubound2", "", true, ""},
    {"ubound4", "", true, ""},
    {"ubound8", "", true, ""},
    {"ubounda", "", false, "k"},
    {"ubounda1", "", false, ""},
    {"ubounda2", "", false, ""},
    {"ubounda4", "", false, ""},
    {"ubounda8", "", false, ""},
    {"uboundaz", "", false, "k"},
    {"uboundaz1", "", false, ""},
    {"uboundaz2", "", false, ""},
    {"uboundaz4", "", false, ""},
    {"uboundaz8", "", false, ""},
    {"verifya", "", false, "k"},
    {"END_OF_PFX_F90,", "", false, ""},
    {"all", "", true, ""},
    {"all_scatterx", "", false, ""},
    {"alls", "", true, ""},
    {"any", "", true, ""},
    {"any_scatterx", "", false, ""},
    {"anys", "", true, ""},
    {"associated", "", true, ""},
    {"associated_chara", "", true, ""},
    {"associated_t", "", true, ""},
    {"associated_tchara", "", true, ""},
    {"barrier", "", false, ""},
    {"block_loop", "", false, ""},
    {"comm_copy", "", false, ""},
    {"comm_free", "", false, ""},
    {"comm_gatherx", "", false, ""},
    {"comm_scatterx", "", false, ""},
    {"copy_out", "", true, ""},
    {"count", "", true, ""},
    {"counts", "", true, ""},
    {"cpu_time", "", false, ""},
    {"cpu_timed", "", false, ""},
    {"cshift", "", true, ""},
    {"cshiftc", "", true, ""},
    {"cshifts", "", true, ""},
    {"cshiftsca", "", true, ""},
    {"cyclic_loop", "", false, ""},
    {"dandta", "", true, ""},
    {"datea", "", false, ""},
    {"datew", "", false, ""},
    {"dotpr", "", true, ""},
    {"eoshift", "", true, ""},
    {"eoshiftca", "", true, ""},
    {"eoshifts", "", true, ""},
    {"eoshiftsa", "", true, ""},
    {"eoshiftsaca", "", true, ""},
    {"eoshiftsca", "", true, ""},
    {"eoshiftss", "", true, ""},
    {"eoshiftssca", "", true, ""},
    {"eoshiftsz", "", true, ""},
    {"eoshiftszca", "", true, ""},
    {"eoshiftz", "", true, ""},
    {"eoshiftzca", "", true, ""},
    {"extent", "", true, ""},
    {"findloc", "", true, "k"},
    {"findlocs", "", true, "k"},
    {"findlocstr", "", true, "k"},
    {"findlocstrs", "", true, "k"},
    {"free", "", true, ""},
    {"freen", "", false, ""},
    {"ftimea", "", true, ""},
    {"ftimew", "", true, ""},
    {"function_entrya", "", false, ""},
    {"function_exit", "", false, ""},
    {"get_scalar", "", true, ""},
    {"global_all", "", false, ""},
    {"global_any", "", false, ""},
    {"global_firstmax", "", false, ""},
    {"global_firstmin", "", false, ""},
    {"global_iall", "", false, ""},
    {"global_iany", "", false, ""},
    {"global_iparity", "", false, ""},
    {"global_lastmax", "", false, ""},
    {"global_lastmin", "", false, ""},
    {"global_maxval", "", false, ""},
    {"global_minval", "", false, ""},
    {"global_parity", "", false, ""},
    {"global_product", "", false, ""},
    {"global_sum", "", false, ""},
    {"globalize", "", false, ""},
    {"iparity", "", false, ""},
    {"iparity_scatterx", "", false, ""},
    {"iparitys", "", true, ""},
    {"iall", "", false, ""},
    {"iall_scatterx", "", false, ""},
    {"ialls", "", true, ""},
    {"iany", "", false, ""},
    {"iany_scatterx", "", false, ""},
    {"ianys", "", true, ""},
    {"idate", "", false, ""},
    {"ilen", "", false, ""},
    {"indexa", "", true, "k"},
    {"indexxa", "", true, "k"},
    {"indexx_cra", "", true, "k"},
    {"indexx_cr_nma", "", true, "k"},
    {"init", "", false, ""},
    {"instance", "", true, ""},
    {"islocal_idx", "", false, ""},
    {"jdate", "", false, ""},
    {"lastval", "", false, ""},
    {"lbound1", "", false, ""},
    {"lbound2", "", false, ""},
    {"lbound4", "", false, ""},
    {"lbound8", "", false, ""},
    {"lbound", "", true, "k"},
    {"lbounda1", "", true, ""},
    {"lbounda2", "", true, ""},
    {"lbounda4", "", true, ""},
    {"lbounda8", "", true, ""},
    {"lbounda", "", true, "k"},
    {"lboundaz1", "", true, ""},
    {"lboundaz2", "", true, ""},
    {"lboundaz4", "", true, ""},
    {"lboundaz8", "", true, ""},
    {"lboundaz", "", true, "k"},
    {"leadz", "", false, ""},
    {"len", "", true, "k"},
    {"lenxa", "", true, "k"},
    {"lenx_cra", "", true, "k"},
    {"lenx_cr_nma", "", true, "k"},
    {"line_entry", "", false, ""},
    {"lineno", "", false, ""},
    {"localize_bounds", "", false, ""},
    {"localize_index", "", false, ""},
    {"matmul", "", true, ""},
    {"maxloc", "", true, "k"},
    {"maxloc_b", "", true, "k"},
    {"maxlocs", "", true, "k"},
    {"maxlocs_b", "", true, "k"},
    {"norm2", "", true, ""},
    {"norm2_nodim", "", true, ""},
    {"maxval", "", true, ""},
    {"maxval_scatterx", "", false, ""},
    {"maxvals", "", true, ""},
    {"member_base", "", false, ""},
    {"minloc", "", true, "k"},
    {"minloc_b", "", true, "k"},
    {"minlocs", "", true, "k"},
    {"minlocs_b", "", true, "k"},
    {"minval", "", true, ""},
    {"minval_scatterx", "", false, ""},
    {"minvals", "", true, ""},
    {"np", "", false, ""},
    {"nullify", "", true, ""},
    {"nullify_chara", "", true, ""},
    {"nullifyx", "", true, ""},
    {"number_of_processors", "", false, "k"},
    {"olap_cshift", "", false, ""},
    {"olap_eoshift", "", false, ""},
    {"olap_shift", "", false, ""},
    {"pack", "", true, ""},
    {"packca", "", true, ""},
    {"packz", "", true, ""},
    {"packzca", "", true, ""},
    {"parity_scatterx", "", false, ""},
    {"permute_section", "", false, ""},
    {"popcnt", "", false, ""},
    {"poppar", "", false, ""},
    {"processors", "", false, ""},
    {"processors_rank", "", false, "k"},
    {"product", "", true, ""},
    {"product_scatterx", "", false, ""},
    {"products", "", true, ""},
    {"ptr_asgn", "", true, ""},
    {"ptr_asgn_chara", "", true, ""},
    {"ptr_assign", "", true, ""},
    {"ptr_assign_chara", "", true, ""},
    {"ptr_assign_charxa", "", true, ""},
    {"ptr_assignx", "", true, ""},
    {"ptr_assn", "", true, ""},
    {"ptr_assn_assumeshp", "", true, ""},
    {"ptr_assn_chara", "", true, ""},
    {"ptr_assn_char_assumeshp", "", true, ""},
    {"ptr_assn_charxa", "", true, ""},
    {"ptr_assn_dchara", "", true, ""},
    {"ptr_assn_dchar_assumeshp", "", true, ""},
    {"ptr_assn_dcharxa", "", true, ""},
    {"ptr_assnx", "", true, ""},
    {"ptr_fix_assumeshp", "", true, ""},
    {"ptr_fix_assumeshp1", "", true, ""},
    {"ptr_fix_assumeshp2", "", true, ""},
    {"ptr_fix_assumeshp3", "", true, ""},
    {"ptr_ina", "", true, ""},
    {"ptr_in_chara", "", true, ""},
    {"ptr_offset", "", true, ""},
    {"ptr_out", "", true, ""},
    {"ptr_out_chara", "", true, ""},
    {"ptr_shape_assn", "", true, ""},
    {"ptr_shape_assnx", "", true, ""},
    {"qopy_in", "", true, ""},
    {"realign", "", true, ""},
    {"redistribute", "", true, ""},
    {"reduce_descriptor", "", true, ""},
    {"reshape", "", true, ""},
    {"reshapeca", "", true, ""},
    {"rnum", "", true, ""},
    {"rnumd", "", true, ""},
    {"rseed", "", true, ""},
    {"secnds", "", true, ""},
    {"secndsd", "", true, ""},
    {"shape", "", true, "k"},
    {"size", "", true, "k"},
    {"spread", "", false, ""},
    {"spread_descriptor", "", true, ""},
    {"spreadca", "", false, ""},
    {"spreadcs", "", false, ""},
    {"spreadsa", "", false, ""},
    {"sum", "", true, ""},
    {"sum_scatterx", "", false, ""},
    {"sums", "", true, ""},
    {"sysclk", "", true, ""},
    {"template", "", true, ""},
    /* AOCC begin */
    {"trailz", "", false, ""},
    /* AOCC end */
    {"transfer", "", true, ""},
    {"type", "", false, ""},
    {"typep", "", false, ""},
    {"ubound1", "", false, ""},
    {"ubound2", "", false, ""},
    {"ubound4", "", false, ""},
    {"ubound8", "", false, ""},
    {"ubound", "", true, "k"},
    {"ubounda1", "", true, ""},
    {"ubounda2", "", true, ""},
    {"ubounda4", "", true, ""},
    {"ubounda8", "", true, ""},
    {"ubounda", "", true, "k"},
    {"uboundaz1", "", true, ""},
    {"uboundaz2", "", true, ""},
    {"uboundaz4", "", true, ""},
    {"uboundaz8", "", true, ""},
    {"uboundaz", "", true, "k"},
    {"unpack", "", true, ""},
    {"unpackca", "", true, ""},
    {"END_OF_PFX_FTN", "", false, ""},
    {"f90io_aux_init", "", false, ""},
    {"f90io_backspace", "", false, ""},
    {"f90io_begin", "", false, ""},
    {"f90io_byte_reada", "", false, ""},
    {"f90io_byte_read64a", "", false, ""},
    {"f90io_byte_writea", "", false, ""},
    {"f90io_byte_write64a", "", false, ""},
    {"f90io_closea", "", false, ""},
    {"f90io_dts_fmtr", "", false, ""},
    {"f90io_dts_fmtw", "", false, ""},
    {"f90io_dts_stat", "", false, ""},
    {"f90io_encode_fmta", "", false, ""},
    {"f90io_encode_fmtv", "", false, ""},
    {"f90io_end", "", false, ""},
    {"f90io_endfile", "", false, ""},
    {"f90io_flush", "", false, ""},
    {"f90io_fmt_reada", "", false, ""},
    {"f90io_fmt_read64_aa", "", false, ""},
    {"f90io_fmt_read_aa", "", false, ""},
    {"f90io_fmt_writea", "", false, ""},
    {"f90io_fmt_write64_aa", "", false, ""},
    {"f90io_fmt_write_aa", "", false, ""},
    {"f90io_fmtr_end", "", false, ""},
    {"f90io_fmtr_inita", "", false, ""},
    {"f90io_fmtr_init03a", "", false, ""},
    {"f90io_fmtr_init2003a", "", false, ""},
    {"f90io_fmtr_initva", "", false, ""},
    {"f90io_fmtr_initv2003a", "", false, ""},
    {"f90io_fmtr_intern_inita", "", false, ""},
    {"f90io_fmtr_intern_inite", "", false, ""},
    {"f90io_fmtr_intern_initev", "", false, ""},
    {"f90io_fmtr_intern_initva", "", false, ""},
    {"f90io_fmtw_end", "", false, ""},
    {"f90io_fmtw_inita", "", false, ""},
    {"f90io_fmtw_init03a", "", false, ""},
    {"f90io_fmtw_initva", "", false, ""},
    {"f90io_fmtw_intern_inita", "", false, ""},
    {"f90io_fmtw_intern_inite", "", false, ""},
    {"f90io_fmtw_intern_initev", "", false, ""},
    {"f90io_fmtw_intern_initva", "", false, ""},
    {"f90io_get_newunit", "", false, ""},
    {"f90io_inquirea", "", false, ""},
    {"f90io_inquire03a", "", false, ""},
    {"f90io_inquire03_2a", "", false, ""},
    {"f90io_inquire2003a", "", false, ""},
    {"f90io_iomsga", "", false, ""},
    {"f90io_iomsg_", "", false, ""},
    {"f90io_ldra", "", false, ""},
    {"f90io_ldr64_aa", "", false, ""},
    {"f90io_ldr_aa", "", false, ""},
    {"f90io_ldr_end", "", false, ""},
    {"f90io_ldr_init", "", false, ""},
    {"f90io_ldr_init03a", "", false, ""},
    {"f90io_ldr_intern_inita", "", false, ""},
    {"f90io_ldr_intern_inite", "", false, ""},
    {"f90io_ldwa", "", false, ""},
    {"f90io_ldw64_aa", "", false, ""},
    {"f90io_ldw_aa", "", false, ""},
    {"f90io_ldw_end", "", false, ""},
    {"f90io_ldw_init", "", false, ""},
    {"f90io_ldw_init03a", "", false, ""},
    {"f90io_ldw_intern_inita", "", false, ""},
    {"f90io_ldw_intern_inite", "", false, ""},
    {"f90io_nml_read", "", true, ""},
    {"f90io_nml_write", "", true, ""},
    {"f90io_nmlr", "", true, ""},
    {"f90io_nmlr_end", "", true, ""},
    {"f90io_nmlr_init", "", true, ""},
    {"f90io_nmlr_init03a", "", true, ""},
    {"f90io_nmlr_intern_inita", "", true, ""},
    {"f90io_nmlw", "", true, ""},
    {"f90io_nmlw_end", "", true, ""},
    {"f90io_nmlw_init", "", true, ""},
    {"f90io_nmlw_init03a", "", true, ""},
    {"f90io_nmlw_intern_inita", "", true, ""},
    {"f90io_open03a", "", false, ""},
    {"f90io_open2003a", "", false, ""},
    {"f90io_open_asynca", "", false, ""},
    {"f90io_open_cvta", "", false, ""},
    {"f90io_open_sharea", "", false, ""},
    {"f90io_print_init", "", false, ""},
    {"f90io_rewind", "", false, ""},
    {"f90io_sc_cq_fmt_write", "", false, ""},  // AOCC
    {"f90io_sc_cq_ldw", "", false, ""},        // AOCC
    {"f90io_sc_cd_fmt_write", "", false, ""},
    {"f90io_sc_cd_ldw", "", false, ""},
    {"f90io_sc_cf_fmt_write", "", false, ""},
    {"f90io_sc_cf_ldw", "", false, ""},
    {"f90io_sc_ch_fmt_write", "", false, ""},
    {"f90io_sc_ch_ldw", "", false, ""},
    {"f90io_sc_d_fmt_write", "", false, ""},
    {"f90io_sc_d_ldw", "", false, ""},
    {"f90io_sc_q_fmt_write", "", false, ""},   // AOCC
    {"f90io_sc_q_ldw", "", false, ""},         // AOCC
    {"f90io_sc_f_fmt_write", "", false, ""},
    {"f90io_sc_f_ldw", "", false, ""},
    {"f90io_sc_fmt_write", "", false, ""},
    {"f90io_sc_i_fmt_write", "", false, ""},
    {"f90io_sc_i_ldw", "", false, ""},
    {"f90io_sc_l_fmt_write", "", false, ""},
    {"f90io_sc_l_ldw", "", false, ""},
    {"f90io_sc_ldw", "", false, ""},
    {"f90io_src_info03a", "", false, ""},
    {"f90io_src_infox03a", "", false, ""},
    {"f90io_swbackspace", "", false, ""},
    {"f90io_unf_asynca", "", false, ""},
    {"f90io_unf_end", "", false, ""},
    {"f90io_unf_init", "", false, ""},
    {"f90io_unf_reada", "", false, ""},
    {"f90io_unf_read64_aa", "", false, ""},
    {"f90io_unf_read_aa", "", false, ""},
    {"f90io_unf_writea", "", false, ""},
    {"f90io_unf_write64_aa", "", false, ""},
    {"f90io_unf_write_aa", "", false, ""},
    {"f90io_usw_end", "", false, ""},
    {"f90io_usw_init", "", false, ""},
    {"f90io_usw_reada", "", false, ""},
    {"f90io_usw_read64_aa", "", false, ""},
    {"f90io_usw_read_aa", "", false, ""},
    {"f90io_usw_writea", "", false, ""},
    {"f90io_usw_write64_aa", "", false, ""},
    {"f90io_usw_write_aa", "", false, ""},
    {"f90io_wait", "", false, ""},
    {"END_OF_IO", "", false, ""},
    {"io_fmt_read", "", false, ""},
    {"io_fmt_read64", "", false, ""},
    {"io_fmt_write", "", false, ""},
    {"io_fmt_write64", "", false, ""},
    {"io_ldr", "", false, ""},
    {"io_ldr64", "", false, ""},
    {"io_ldw", "", false, ""},
    {"io_ldw64", "", false, ""},
    {"io_unf_read", "", false, ""},
    {"io_unf_read64", "", false, ""},
    {"io_unf_write", "", false, ""},
    {"io_unf_write64", "", false, ""},
    {"io_usw_read", "", false, ""},
    {"io_usw_read64", "", false, ""},
    {"io_usw_write", "", false, ""},
    {"io_usw_write64", "", false, ""},
    {"END_OF_FTNIO", "", false, ""},
};

#ifdef DEBUG
void
dump_FtnRteRtn(FtnRtlEnum rteRtn)
{
  fprintf(stderr, "ftnRtlRtns[%d]:\n", rteRtn);
  fprintf(stderr, "  baseNm: %s\n", ftnRtlRtns[rteRtn].baseNm);
  fprintf(stderr, "  I8Descr: %s\n",
          ftnRtlRtns[rteRtn].I8Descr ? "true" : "false");
  if (strlen(ftnRtlRtns[rteRtn].largeRetValPrefix) != 0) {
    fprintf(stderr, "  largeRetValPrefix: %s\n",
            ftnRtlRtns[rteRtn].largeRetValPrefix);
  } else {
    fprintf(stderr, "  largeRetValPrefix: NULL\n");
  }
  if (strlen(ftnRtlRtns[rteRtn].fullNm) != 0) {
    fprintf(stderr, "  fullNm: %s\n", ftnRtlRtns[rteRtn].fullNm);
  } else {
    fprintf(stderr, "  fullNm: NULL\n");
  }
}
#endif

/** \brief given a FtnRtlEnum, return the RTL routine name */
char *
mkRteRtnNm(FtnRtlEnum rteRtn)
{
  const char *prefixes[4] = {"f90_", "fort_", "", "ftn"};

  assert(strcmp(ftnRtlRtns[END_OF_FTNIO].baseNm, "END_OF_FTNIO") == 0,
         "mkRteRtnNm: RTL name table and RTL name enum are out of sync", rteRtn,
         ERR_Severe);
  assert(rteRtn > RTE_no_rtn && rteRtn < END_OF_FTNIO,
         "mkRteRtnNm: invalid rteRtn enum", rteRtn, ERR_Severe);

  if (strlen(ftnRtlRtns[rteRtn].fullNm) == 0) {
    if (rteRtn < END_OF_PFX_F90) {
      strcat(ftnRtlRtns[rteRtn].fullNm, prefixes[0]);
    } else if (rteRtn > END_OF_PFX_F90 && rteRtn < END_OF_PFX_FTN) {
      strcat(ftnRtlRtns[rteRtn].fullNm, prefixes[1]);
    } else if (rteRtn > END_OF_PFX_FTN && rteRtn < END_OF_IO) {
      strcat(ftnRtlRtns[rteRtn].fullNm, prefixes[2]);
    } else if (rteRtn > END_OF_IO && rteRtn < END_OF_FTNIO) {
      strcat(ftnRtlRtns[rteRtn].fullNm, prefixes[3]);
    }

    if (XBIT(124, 0x10) &&
        strncmp("k", ftnRtlRtns[rteRtn].largeRetValPrefix, 1) == 0) {
      strcat(ftnRtlRtns[rteRtn].fullNm, ftnRtlRtns[rteRtn].largeRetValPrefix);
    }

    /* FIXME: what about (XBIT(68, 0x1) && XBIT(68, 0x2), see semfunc.c,
     *        transfrm.c
     */
    if (XBIT(124, 0x8) &&
        (strncmp("d", ftnRtlRtns[rteRtn].largeRetValPrefix, 1) == 0 ||
         strncmp("cd", ftnRtlRtns[rteRtn].largeRetValPrefix, 2) == 0)) {
      strcat(ftnRtlRtns[rteRtn].fullNm, ftnRtlRtns[rteRtn].largeRetValPrefix);
    }

    strcat(ftnRtlRtns[rteRtn].fullNm, ftnRtlRtns[rteRtn].baseNm);

    if (ftnRtlRtns[rteRtn].I8Descr && (XBIT(68, 0x1))) {
      strcat(ftnRtlRtns[rteRtn].fullNm, "_i8");
    }
  }
  assert(strlen(ftnRtlRtns[rteRtn].fullNm) > 0,
         "mkRteRtnNm: return NULL name\n", rteRtn, ERR_Severe);
  return ftnRtlRtns[rteRtn].fullNm;
}

static void
stripI8DescrSuffix(char *inNm, char *outNm)
{
  int nmLen = strlen(inNm);

  if (nmLen <= 3) {
    outNm[0] = '\0';
    return;
  }

  assert(nmLen < MAXIDLEN, "stripI8DescrSuffix: name too big", nmLen,
         ERR_Severe);

  if (XBIT(68, 0x1)) {
    nmLen -= 3; /* strip "_i8" */
  }
  strncpy(outNm, inNm, nmLen);
  outNm[nmLen] = '\0';
}

typedef struct {
  FtnRtlEnum rtlRtn;
  int ftype;
} F90TmplSectRtns;

static F90TmplSectRtns f90TmplSectRtns[] = {
    {RTE_sect, FTYPE_SECT},           {RTE_sect1, FTYPE_SECT},
    {RTE_sect1v, FTYPE_SECT},         {RTE_sect2, FTYPE_SECT},
    {RTE_sect2v, FTYPE_SECT},         {RTE_sect3, FTYPE_SECT},
    {RTE_sect3v, FTYPE_SECT},         {RTE_template, FTYPE_TEMPLATE},
    {RTE_template1, FTYPE_TEMPLATE1}, {RTE_template1v, FTYPE_TEMPLATE1V},
    {RTE_template2, FTYPE_TEMPLATE2}, {RTE_template2v, FTYPE_TEMPLATE2V},
    {RTE_template3, FTYPE_TEMPLATE3}, {RTE_template3v, FTYPE_TEMPLATE3V},
};

static int
setTmplSectRtnFtype(int i)
{
  int retFtype;

  retFtype = f90TmplSectRtns[i].ftype;
  /* assert ftnRtlRtns[i].I8Descr == true */
  if ((XBIT(68, 0x1))) {
    retFtype |= FTYPE_I8;
  }
  return retFtype;
}

int
getF90TmplSectRtn(char *rtnNm)
{
  int l, h, m, r;
  char *tmplSectNm;
  int retFtype = 0;
  int compLen;
  char cpyRtnNm[MAXIDLEN];
  char cpyTmplSectNm[MAXIDLEN];

  stripI8DescrSuffix(rtnNm, cpyRtnNm);
  if (cpyRtnNm[0] == '\0') {
    /* name too short to be a RTL descriptor rtn */
    return 0;
  }

  l = 0;
  h = sizeof(f90TmplSectRtns) / sizeof(F90TmplSectRtns) - 1;

  /* The majority of this function's invocations will return 0,
   * check if routine names are are out of bounds
   */
  tmplSectNm = mkRteRtnNm(f90TmplSectRtns[l].rtlRtn);
  stripI8DescrSuffix(tmplSectNm, cpyTmplSectNm);
  r = strcmp(cpyRtnNm, cpyTmplSectNm);
  if (r == 0) {
    return setTmplSectRtnFtype(l);
  } else if (r < 0)
    return 0;

  tmplSectNm = mkRteRtnNm(f90TmplSectRtns[h].rtlRtn);
  stripI8DescrSuffix(tmplSectNm, cpyTmplSectNm);
  r = strcmp(cpyRtnNm, cpyTmplSectNm);
  if (r == 0) {
    return setTmplSectRtnFtype(h);
  } else if (r > 0)
    return 0;

  while (l <= h) {
    m = (h + l) / 2;

    tmplSectNm = mkRteRtnNm(f90TmplSectRtns[m].rtlRtn);
    stripI8DescrSuffix(tmplSectNm, cpyTmplSectNm);

    r = strcmp(cpyRtnNm, cpyTmplSectNm);
    if (r == 0) {
      retFtype = setTmplSectRtnFtype(m);
      break;
    }
    if (r < 0) {
      h = m - 1;
    } else if (r > 0) {
      l = m + 1;
    }
  }

  return retFtype;
}

