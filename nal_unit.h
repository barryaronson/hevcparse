#ifndef NAL_UNIT_H
#define NAL_UNIT_H

#include <vector>
#include <fstream>
#include <iomanip>

#ifdef NDEBUG
#define PRINT_NAL_UNIT(x)	((void)(x))
#else
#define PRINT_NAL_UNIT(x) \
	( \
	 std::cout << "NAL unit type = " << std::setw(12) << std::left << (x) << "\tNumBytesInNalUnit = " << num_bytes_in_nal_unit << std::endl \
	 )
#endif

struct nal_unit_header {
	bool forbidden_zero_bit : 1;
	unsigned nal_unit_type : 6;
	unsigned nuh_layer_id : 6;
	unsigned nuh_temporal_id_plus1 : 3;
};
constexpr size_t nal_unit_header_size = (1 + 6 + 6 + 3) / 8;	// due to padding, 'sizeof(nal_unit_header)' may yield a too large value

constexpr size_t nal_type_table_size = 1 << 6; // 6 bits allotted to 'nal_unit_type' = 64

class nal_unit {

public:
	nal_unit();
	void read(std::ifstream& rbsp);
	void process(void);
	void find_first(std::ifstream& rbsp);
	
private:
  	// where the NAL unit is stored
	using nal_unit_buf_t = std::vector<char>;
	nal_unit_buf_t nal_unit_buf;
  	size_t num_bytes_in_nal_unit;

#ifndef NAL_UNIT_USE_SWITCH
  	// process each NAL unit based on its type; use NAL unit type to index into array of pointers to functions for handling specific NAL units
	using nal_func = void (nal_unit::*)(void);
	nal_func process_nal_type[nal_type_table_size];
#endif
  
	// functions to handle each of the NAL unit types
	void trail_n(void);
	void trail_r(void);
	void tsa_n(void);
	void tsa_r(void);
	void stsa_n(void);
	void stsa_r(void);
	void radl_n(void);
	void radl_r(void);
	void rasl_n(void);
	void rasl_r(void);
	void rsv_vcl_n10(void);
	void rsv_vcl_n12(void);
	void rsv_vcl_n14(void);
	void rsv_vcl_r11(void);
	void rsv_vcl_r13(void);
	void rsv_vcl_r15(void);
	void bla_w_lp(void);
	void bla_w_radl(void);
	void bla_n_lp(void);
	void idr_w_radl(void);
	void idr_n_lp(void);
	void cra_nut(void);
	void rsv_irap_vcl22(void);
	void rsv_irap_vcl23(void);
	void rsv_vcl24(void);
	void rsv_vcl25(void);
	void rsv_vcl26(void);
	void rsv_vcl27(void);
	void rsv_vcl28(void);
	void rsv_vcl29(void);
	void rsv_vcl30(void);
	void rsv_vcl31(void);
	void vps_nut(void);
	void sps_nut(void);
	void pps_nut(void);
	void aud_nut(void);
	void eos_nut(void);
	void eob_nut(void);
	void fd_nut(void);
	void prefix_sei_nut(void);
	void suffix_sei_nut(void);
	void rsv_nvcl41(void);
	void rsv_nvcl42(void);
	void rsv_nvcl43(void);
	void rsv_nvcl44(void);
	void rsv_nvcl45(void);
	void rsv_nvcl46(void);
	void rsv_nvcl47(void);
	void unspec48(void);
	void unspec49(void);
	void unspec50(void);
	void unspec51(void);
	void unspec52(void);
	void unspec53(void);
	void unspec54(void);
	void unspec55(void);
	void unspec56(void);
	void unspec57(void);
	void unspec58(void);
	void unspec59(void);
	void unspec60(void);
	void unspec61(void);
	void unspec62(void);
	void unspec63(void);

};

enum nal_types {
	TRAIL_N			= 0,
	TRAIL_R			= 1,
	TSA_N			= 2,
	TSA_R			= 3,
	STSA_N			= 4,
	STSA_R			= 5,
	RADL_N			= 6,
	RADL_R			= 7,
	RASL_N			= 8,
	RASL_R			= 9,
	RSV_VCL_N10		= 10,
	RSV_VCL_N12		= 12,
	RSV_VCL_N14		= 14,
	RSV_VCL_R11		= 11,
	RSV_VCL_R13		= 13,
	RSV_VCL_R15		= 15,
	BLA_W_LP		= 16,
	BLA_W_RADL		= 17,
	BLA_N_LP		= 18,
	IDR_W_RADL		= 19,
	IDR_N_LP		= 20,
	CRA_NUT			= 21,
	RSV_IRAP_VCL22	= 22,
	RSV_IRAP_VCL23	= 23,
	RSV_VCL24		= 24,
	RSV_VCL25		= 25,
	RSV_VCL26		= 26,
	RSV_VCL27		= 27,
	RSV_VCL28		= 28,
	RSV_VCL29		= 29,
	RSV_VCL30		= 30,
	RSV_VCL31		= 31,
	VPS_NUT			= 32,
	SPS_NUT			= 33,
	PPS_NUT			= 34,
	AUD_NUT			= 35,
	EOS_NUT			= 36,
	EOB_NUT			= 37,
	FD_NUT			= 38,
	PREFIX_SEI_NUT	= 39,
	SUFFIX_SEI_NUT	= 40,
	RSV_NVCL41		= 41,
	RSV_NVCL42		= 42,
	RSV_NVCL43		= 43,
	RSV_NVCL44		= 44,
	RSV_NVCL45		= 45,
	RSV_NVCL46		= 46,
	RSV_NVCL47		= 47,
	UNSPEC48		= 48,
	UNSPEC49		= 49,
	UNSPEC50		= 50,
	UNSPEC51		= 51,
	UNSPEC52		= 52,
	UNSPEC53		= 53,
	UNSPEC54		= 54,
	UNSPEC55		= 55,
	UNSPEC56		= 56,
	UNSPEC57		= 57,
	UNSPEC58		= 58,
	UNSPEC59		= 59,
	UNSPEC60		= 60,
	UNSPEC61		= 61,
	UNSPEC62		= 62,
	UNSPEC63		= 63
};

#endif // NAL_UNIT_H
