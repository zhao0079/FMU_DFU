#include "opfwimage.h"
#include <QFile>

OPFWImage::OPFWImage(const QString &from_path)
{
	QFile			*fwf;
	uchar			*mapped;
	qint64			file_size;
	fw_version_info	*fwvi;
	const uint8_t	magic[] = {'O', 'p', 'F', 'w'};

	fwf = new QFile(from_path);
	file_size = fwf->size();

	// default to "no data"
	size = 0;

	if (file_size < (qint64)sizeof(fw_version_info))
		return;

	mapped = fwf->map(0, file_size);
	if (mapped == 0)
		return;

	fwvi = (fw_version_info *)(mapped + file_size) - 1;
	if (fwvi->magic != magic)
		return;

	bytes = new QByteArray((const char *)mapped, size);

	board_type = fwvi->board_type;
	board_revision = fwvi->board_revision;
	memcpy(sha1_sum, fwvi->sha1sum, 20);
	size = file_size - sizeof(fw_version_info);

	crc = 0; // XXX TBD
}

OPFWImage::~OPFWImage()
{
	if (bytes)
		delete bytes;
}
