#include <iostream>

struct TLV {
  uint16_t length;
  uint8_t type;
  uint8_t* data;
};

struct Message {
	uint64_t id;
	int32_t power_offset;
	uint8_t num_valid_tlv;
	TLV* TLVs;
	uint32_t CRC;

	Message(uint64_t id
	      , int32_t power_offset
	      , uint8_t num_valid_tlv
	      , TLV* TLVs
	      , uint32_t CRC) : id(id)
	      , power_offset (power_offset)
	      , num_valid_tlv(num_valid_tlv)
	      , TLVs(TLVs)
	      , CRC(CRC) {}
	// TODO: CRC calc
};

int main() {
// prepare some data
static const uint8_t num = 3;
uint8_t data[num];
uint8_t* pd[num];
  
for (size_t i = 0; i< num; ++i) {
  data[i] = '2'+i;
  pd[i] = &data[i];
}
// init TLV array  
TLV arr[3] {{8,0,pd[0]}, {8,0,pd[1]}, {8,0,pd[2]}};

// Pack TLV array in message
Message m = Message(0, 2, 3, arr, 4);  

std::cout<<"Data before serialize: "
  <<*m.TLVs[1].data<<'\n';

// Serialize
char* sm = reinterpret_cast<char*>(&m);

// Deserialize
Message* new_m = reinterpret_cast<Message*>(sm);  

std::cout<<"Data after deserialize: "
  <<*new_m->TLVs[1].data<<'\n';
}

