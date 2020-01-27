#include <iostream>

#include "nal_unit.h"

void nal_unit::find_first(std::ifstream& rbsp)
{
	int num_zeros = 0;
	char byte;

	// find first start code
	while (rbsp.get(byte) && byte == 0x00)
		num_zeros++;
	if (rbsp.eof() || byte != 0x01 || num_zeros < 3)
		exit(EXIT_FAILURE);
}

void nal_unit::read(std::ifstream& rbsp)
{
	nal_unit_buf.clear();
	int num_zeros = 0;
	char byte;

	while (rbsp.get(byte)) {
		nal_unit_buf.push_back(byte);	// normal situation: extracting NAL unit bytes

		if (byte == 0x00) {	// potentially the beginning of the next NAL unit
			num_zeros++;

			while (rbsp.get(byte)) {
				nal_unit_buf.push_back(byte);

				if (byte == 0x00) {	// still looking like the beginning of the next NAL unit
					num_zeros++;
				} else if (byte == 0x01) {	// at the beginning of the next NAL unit ...
				  if (num_zeros >= 2) {		// ... if enough zeros have passed
						nal_unit_buf.pop_back();		// remove 0x01
						do {
							nal_unit_buf.pop_back();	// remove all the 0x00s
						} while (--num_zeros);
						num_bytes_in_nal_unit = nal_unit_buf.size();
						return;
				  } else {	// not at the beginning of the next NAL unit 
						num_zeros = 0;
						break;
					}
				} else {	// not at the beginning of the next NAL unit 
					num_zeros = 0;
					break;
				}
			}
		}
	}
}

void nal_unit::trail_n(void)
{
	PRINT_NAL_UNIT("train_n");
}

void nal_unit::trail_r(void)
{
	PRINT_NAL_UNIT("trail_r");
}

void nal_unit::tsa_n(void)
{
	PRINT_NAL_UNIT("tsa_n");
}

void nal_unit::tsa_r(void)
{
	PRINT_NAL_UNIT("tsa_r");
}

void nal_unit::stsa_n(void)
{
	PRINT_NAL_UNIT("stsa_n");
}

void nal_unit::stsa_r(void)
{
	PRINT_NAL_UNIT("stsa_r");
}

void nal_unit::radl_n(void)
{
	PRINT_NAL_UNIT("radl_n");
}

void nal_unit::radl_r(void)
{
	PRINT_NAL_UNIT("radl_r");
}

void nal_unit::rasl_n(void)
{
	PRINT_NAL_UNIT("rasl_n");
}

void nal_unit::rasl_r(void)
{
	PRINT_NAL_UNIT("rasl_r");
}

void nal_unit::rsv_vcl_n10(void)
{
	PRINT_NAL_UNIT("rsv_vcl_n10");
}

void nal_unit::rsv_vcl_n12(void)
{
	PRINT_NAL_UNIT("rsv_vcl_n12");
}

void nal_unit::rsv_vcl_n14(void)
{
	PRINT_NAL_UNIT("rsv_vcl_n14");
}

void nal_unit::rsv_vcl_r11(void)
{
	PRINT_NAL_UNIT("rsv_vcl_r11");
}

void nal_unit::rsv_vcl_r13(void)
{
	PRINT_NAL_UNIT("rsv_vcl_r13");
}

void nal_unit::rsv_vcl_r15(void)
{
	PRINT_NAL_UNIT("rsv_vcl_r15");
}

void nal_unit::bla_w_lp(void)
{
	PRINT_NAL_UNIT("bla_w_lp");
}

void nal_unit::bla_w_radl(void)
{
	PRINT_NAL_UNIT("bla_w_radl");
}

void nal_unit::bla_n_lp(void)
{
	PRINT_NAL_UNIT("bla_n_lp");
}

void nal_unit::idr_w_radl(void)
{
	PRINT_NAL_UNIT("idr_w_radl");
}

void nal_unit::idr_n_lp(void)
{
	PRINT_NAL_UNIT("idr_n_lp");
}

void nal_unit::cra_nut(void)
{
	PRINT_NAL_UNIT("cra_nut");
}

void nal_unit::rsv_irap_vcl22(void)
{
	PRINT_NAL_UNIT("rsv_irap_vcl22");
}

void nal_unit::rsv_irap_vcl23(void)
{
	PRINT_NAL_UNIT("rsv_irap_vcl23");
}

void nal_unit::rsv_vcl24(void)
{
	PRINT_NAL_UNIT("rsv_vcl24");
}

void nal_unit::rsv_vcl25(void)
{
	PRINT_NAL_UNIT("rsv_vcl25");
}

void nal_unit::rsv_vcl26(void)
{
	PRINT_NAL_UNIT("rsv_vcl26");
}

void nal_unit::rsv_vcl27(void)
{
	PRINT_NAL_UNIT("rsv_vcl27");
}

void nal_unit::rsv_vcl28(void)
{
	PRINT_NAL_UNIT("rsv_vcl28");
}

void nal_unit::rsv_vcl29(void)
{
	PRINT_NAL_UNIT("rsv_vcl29");
}

void nal_unit::rsv_vcl30(void)
{
	PRINT_NAL_UNIT("rsv_vcl30");
}

void nal_unit::rsv_vcl31(void)
{
	PRINT_NAL_UNIT("rsv_vcl31");
}

void nal_unit::vps_nut(void)
{
	PRINT_NAL_UNIT("vps_nut");
}

void nal_unit::sps_nut(void)
{
	PRINT_NAL_UNIT("sps_nut");
}

void nal_unit::pps_nut(void)
{
	PRINT_NAL_UNIT("pps_nut");
}

void nal_unit::aud_nut(void)
{
	PRINT_NAL_UNIT("aud_nut");
}

void nal_unit::eos_nut(void)
{
	PRINT_NAL_UNIT("eos_nut");
}

void nal_unit::eob_nut(void)
{
	PRINT_NAL_UNIT("eob_nut");
}

void nal_unit::fd_nut(void)
{
	PRINT_NAL_UNIT("fd_nut");
}

void nal_unit::prefix_sei_nut(void)
{
	PRINT_NAL_UNIT("prefix_sei_nut");
}

void nal_unit::suffix_sei_nut(void)
{
	PRINT_NAL_UNIT("suffix_sei_nut");
}

void nal_unit::rsv_nvcl41(void)
{
	PRINT_NAL_UNIT("rsv_nvcl41");
}

void nal_unit::rsv_nvcl42(void)
{
	PRINT_NAL_UNIT("rsv_nvcl42");
}

void nal_unit::rsv_nvcl43(void)
{
	PRINT_NAL_UNIT("rsv_nvcl43");
}

void nal_unit::rsv_nvcl44(void)
{
	PRINT_NAL_UNIT("rsv_nvcl44");
}

void nal_unit::rsv_nvcl45(void)
{
	PRINT_NAL_UNIT("rsv_nvcl45");
}

void nal_unit::rsv_nvcl46(void)
{
	PRINT_NAL_UNIT("rsv_nvcl46");
}

void nal_unit::rsv_nvcl47(void)
{
	PRINT_NAL_UNIT("rsv_nvcl47");
}

void nal_unit::unspec48(void)
{
	PRINT_NAL_UNIT("unspec48");
}

void nal_unit::unspec49(void)
{
	PRINT_NAL_UNIT("unspec49");
}

void nal_unit::unspec50(void)
{
	PRINT_NAL_UNIT("unspec50");
}

void nal_unit::unspec51(void)
{
	PRINT_NAL_UNIT("unspec51");
}

void nal_unit::unspec52(void)
{
	PRINT_NAL_UNIT("unspec52");
}

void nal_unit::unspec53(void)
{
	PRINT_NAL_UNIT("unspec53");
}

void nal_unit::unspec54(void)
{
	PRINT_NAL_UNIT("unspec54");
}

void nal_unit::unspec55(void)
{
	PRINT_NAL_UNIT("unspec55");
}

void nal_unit::unspec56(void)
{
	PRINT_NAL_UNIT("unspec56");
}

void nal_unit::unspec57(void)
{
	PRINT_NAL_UNIT("unspec57");
}

void nal_unit::unspec58(void)
{
	PRINT_NAL_UNIT("unspec58");
}

void nal_unit::unspec59(void)
{
	PRINT_NAL_UNIT("unspec59");
}

void nal_unit::unspec60(void)
{
	PRINT_NAL_UNIT("unspec60");
}

void nal_unit::unspec61(void)
{
	PRINT_NAL_UNIT("unspec61");
}

void nal_unit::unspec62(void)
{
	PRINT_NAL_UNIT("unspec62");
}

void nal_unit::unspec63(void)
{
	PRINT_NAL_UNIT("unspec63");
}

nal_unit::nal_unit()
{
#ifndef NAL_UNIT_USE_SWITCH
	process_nal_type[TRAIL_N]			= &nal_unit::trail_n;
	process_nal_type[TRAIL_R]			= &nal_unit::trail_r;
	process_nal_type[TSA_N]				= &nal_unit::tsa_n;
	process_nal_type[TSA_R]				= &nal_unit::tsa_r;
	process_nal_type[STSA_N]			= &nal_unit::stsa_n;
	process_nal_type[STSA_R]			= &nal_unit::stsa_r;
	process_nal_type[RADL_N]			= &nal_unit::radl_n;
	process_nal_type[RADL_R]			= &nal_unit::radl_r;
	process_nal_type[RASL_N]			= &nal_unit::rasl_n;
	process_nal_type[RASL_R]			= &nal_unit::rasl_r;
	process_nal_type[RSV_VCL_N10]		= &nal_unit::rsv_vcl_n10;
	process_nal_type[RSV_VCL_N12]		= &nal_unit::rsv_vcl_n12;
	process_nal_type[RSV_VCL_N14]		= &nal_unit::rsv_vcl_n14;
	process_nal_type[RSV_VCL_R11]		= &nal_unit::rsv_vcl_r11;
	process_nal_type[RSV_VCL_R13]		= &nal_unit::rsv_vcl_r13;
	process_nal_type[RSV_VCL_R15]		= &nal_unit::rsv_vcl_r15;
	process_nal_type[BLA_W_LP]			= &nal_unit::bla_w_lp;
	process_nal_type[BLA_W_RADL]		= &nal_unit::bla_w_radl;
	process_nal_type[BLA_N_LP]			= &nal_unit::bla_n_lp;
	process_nal_type[IDR_W_RADL]		= &nal_unit::idr_w_radl;
	process_nal_type[IDR_N_LP]			= &nal_unit::idr_n_lp;
	process_nal_type[CRA_NUT]			= &nal_unit::cra_nut;
	process_nal_type[RSV_IRAP_VCL22]	= &nal_unit::rsv_irap_vcl22;
	process_nal_type[RSV_IRAP_VCL23]	= &nal_unit::rsv_irap_vcl23;
	process_nal_type[RSV_VCL24]			= &nal_unit::rsv_vcl24;
	process_nal_type[RSV_VCL25]			= &nal_unit::rsv_vcl25;
	process_nal_type[RSV_VCL26]			= &nal_unit::rsv_vcl26;
	process_nal_type[RSV_VCL27]			= &nal_unit::rsv_vcl27;
	process_nal_type[RSV_VCL28]			= &nal_unit::rsv_vcl28;
	process_nal_type[RSV_VCL29]			= &nal_unit::rsv_vcl29;
	process_nal_type[RSV_VCL30]			= &nal_unit::rsv_vcl30;
	process_nal_type[RSV_VCL31]			= &nal_unit::rsv_vcl31;
	process_nal_type[VPS_NUT]			= &nal_unit::vps_nut;
	process_nal_type[SPS_NUT]			= &nal_unit::sps_nut;
	process_nal_type[PPS_NUT]			= &nal_unit::pps_nut;
	process_nal_type[AUD_NUT]			= &nal_unit::aud_nut;
	process_nal_type[EOS_NUT]			= &nal_unit::eos_nut;
	process_nal_type[EOB_NUT]			= &nal_unit::eob_nut;
	process_nal_type[FD_NUT]			= &nal_unit::fd_nut;
	process_nal_type[PREFIX_SEI_NUT]	= &nal_unit::prefix_sei_nut;
	process_nal_type[SUFFIX_SEI_NUT]	= &nal_unit::suffix_sei_nut;
	process_nal_type[RSV_NVCL41]		= &nal_unit::rsv_nvcl41;
	process_nal_type[RSV_NVCL42]		= &nal_unit::rsv_nvcl42;
	process_nal_type[RSV_NVCL43]		= &nal_unit::rsv_nvcl43;
	process_nal_type[RSV_NVCL44]		= &nal_unit::rsv_nvcl44;
	process_nal_type[RSV_NVCL45]		= &nal_unit::rsv_nvcl45;
	process_nal_type[RSV_NVCL46]		= &nal_unit::rsv_nvcl46;
	process_nal_type[RSV_NVCL47]		= &nal_unit::rsv_nvcl47;
	process_nal_type[UNSPEC48]			= &nal_unit::unspec48;
	process_nal_type[UNSPEC49]			= &nal_unit::unspec49;
	process_nal_type[UNSPEC50]			= &nal_unit::unspec50;
	process_nal_type[UNSPEC51]			= &nal_unit::unspec51;
	process_nal_type[UNSPEC52]			= &nal_unit::unspec52;
	process_nal_type[UNSPEC53]			= &nal_unit::unspec53;
	process_nal_type[UNSPEC54]			= &nal_unit::unspec54;
	process_nal_type[UNSPEC55]			= &nal_unit::unspec55;
	process_nal_type[UNSPEC56]			= &nal_unit::unspec56;
	process_nal_type[UNSPEC57]			= &nal_unit::unspec57;
	process_nal_type[UNSPEC58]			= &nal_unit::unspec58;
	process_nal_type[UNSPEC59]			= &nal_unit::unspec59;
	process_nal_type[UNSPEC60]			= &nal_unit::unspec60;
	process_nal_type[UNSPEC61]			= &nal_unit::unspec61;
	process_nal_type[UNSPEC62]			= &nal_unit::unspec62;
	process_nal_type[UNSPEC63]			= &nal_unit::unspec63;
#endif
};

#ifdef NAL_UNIT_USE_SWITCH

void nal_unit::process(void)
{
	if (num_bytes_in_nal_unit < nal_unit_header_size)	// check to see if there was enough read to at least contain a NAL unit header
		exit(EXIT_FAILURE);

	switch (((nal_unit_header*)nal_unit_buf.data())->nal_unit_type) {
	case TRAIL_N:
		trail_n();
		break;
	case TRAIL_R:
		trail_r();
		break;
	case TSA_N:
		tsa_n();
		break;
	case TSA_R:
		tsa_r();
		break;
	case STSA_N:
		stsa_n();
		break;
	case STSA_R:
		stsa_r();
		break;
	case RADL_N:
		radl_n();
		break;
	case RADL_R:
		radl_r();
		break;
	case RASL_N:
		rasl_n();
		break;
	case RASL_R:
		rasl_r();
		break;
	case RSV_VCL_N10:
	case RSV_VCL_N12:
	case RSV_VCL_N14:
	case RSV_VCL_R11:
	case RSV_VCL_R13:
	case RSV_VCL_R15:
		std::cout << "RSV_VCL\n";
		break;
	case BLA_W_LP:
		bla_w_lp();
		break;
	case BLA_W_RADL:
		bla_w_radl();
		break;
	case BLA_N_LP:
		bla_n_lp();
		break;
	case IDR_W_RADL:
		idr_w_radl();
		break;
	case IDR_N_LP:
		idr_n_lp();
		break;
	case CRA_NUT:
		cra_nut();
		break;
	case RSV_IRAP_VCL22:
	case RSV_IRAP_VCL23:
		std::cout << "RSV_IRAP_VCL\n";
		break;
	case RSV_VCL24:
	case RSV_VCL25:
	case RSV_VCL26:
	case RSV_VCL27:
	case RSV_VCL28:
	case RSV_VCL29:
	case RSV_VCL30:
	case RSV_VCL31:
		std::cout << "RSV_VCL\n";
		break;
	case VPS_NUT:
		vps_nut();
		break;
	case SPS_NUT:
		sps_nut();
		break;
	case PPS_NUT:
		pps_nut();
		break;
	case AUD_NUT:
		aud_nut();
		break;
	case EOS_NUT:
		eos_nut();
		break;
	case EOB_NUT:
		eob_nut();
		break;
	case FD_NUT:
		fd_nut();
		break;
	case PREFIX_SEI_NUT:
		prefix_sei_nut();
		break;
	case SUFFIX_SEI_NUT:
		suffix_sei_nut();
		break;
	case RSV_NVCL41:
	case RSV_NVCL42:
	case RSV_NVCL43:
	case RSV_NVCL44:
	case RSV_NVCL45:
	case RSV_NVCL46:
	case RSV_NVCL47:
		std::cout << "RSV_NVCL\n";
		break;
	case UNSPEC48:
	case UNSPEC49:
	case UNSPEC50:
	case UNSPEC51:
	case UNSPEC52:
	case UNSPEC53:
	case UNSPEC54:
	case UNSPEC55:
	case UNSPEC56:
	case UNSPEC57:
	case UNSPEC58:
	case UNSPEC59:
	case UNSPEC60:
	case UNSPEC61:
	case UNSPEC62:
	case UNSPEC63:
		std::cout << "UNSPEC\n";
		break;
	}
}

#else

void nal_unit::process(void)
{
  if (num_bytes_in_nal_unit < nal_unit_header_size)	// check to see if there was enough read to at least contain a NAL unit header
	exit(EXIT_FAILURE);

  // we don't have to worry about 'nal_unit_type' being out of range as it can't be more that 6 bits, which was used to determine the size of 'nal_unit_buf'
  (this->*process_nal_type[((nal_unit_header*)nal_unit_buf.data())->nal_unit_type])();	// look up pointer to function handling this NAL unit type and call it
}

#endif
