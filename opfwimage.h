#ifndef OPFWIMAGE_H
#define OPFWIMAGE_H

#include <Qstring>
#include <stdint.h>

class OPFWImage
{
public:
	OPFWImage(const QString &from_path);
	~OPFWImage();

	uint8_t			board_type;
	uint8_t			board_revision;
	uint8_t			sha1_sum[20];
	uint32_t		crc;
	uint32_t		size;

	const QByteArray	*bytes;
private:

	struct __attribute__((packed)) fw_version_info {
		uint8_t		magic[4];
		uint32_t	commit_hash_prefix;
		uint32_t	timestamp;
		uint8_t		board_type;
		uint8_t		board_revision;
		uint8_t		commit_tag_name[26];
		uint8_t		sha1sum[20];
		uint8_t		pad[40];
	};
};

#endif // OPFWIMAGE_H
