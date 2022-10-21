# Changelog

## [2022.10.21] - 21-10-2022
### Added
* ADDED: Perfect MemCpy, MemCmp, MemCat functions
* ADDED: *StructWord.api files added
* ADDED: Code sniplets added to MINGW32

### Changes
* UPDATE: Types section in ini files are updated with windows data types
* UPDATE: Debug parameters are updated with no dynamic base
* UPDATE: *.api files updated and fixed

## [2022.09.06] - 06-09-2022
### Added
* Debugcommand lines added to MINGWxx/INI files
* OPENFILENAMEW added to MINGW64Struct.api
* Some interger types from Windows base types added to MASM64.ini:
  * INT, INT8, INT16, INT32, INT64, INT_PTR
  * UINT8, UINT16, UINT32, UINT64, UINT_PTR
* API constants added CreateFileMapping & CreateFileMappingNuma
* MINGW64Word.api was totally wrong i have changed that file!
* Sniplets-Code added to MINGW64
* ADDED: LoadImage, CreateThread and CreateFont Constants
* FIX: LoadCursor and LoadIcon apis shouldn't get hInst as parameter. They should get null.
* FIX: Some apis mistakenly get 0 instead of null
* FIX: Some cosmetic changes made
* ADDED: Common Control style constants to api files

### Changes
* OPENFILENAME structure in MINGW64 updated to 64bit version of it


## [2022.09.02] - 02-09-2022
### Added
* Added: Changelog
* Added: gitattributes

### Changes
* Corrected: Some handle sizes change from 4 to 8 in MINGW64Type
* Updated: Readme
* Updated: gitignore
* Changed: TabToSpc set to 1 on both ini files
