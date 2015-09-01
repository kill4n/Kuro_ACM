file(REMOVE_RECURSE
  "../../../build_Windows/libMOTORINT.pdb"
  "../../../build_Windows/libMOTORINT.dll"
  "../../../build_Windows/libMOTORINT.dll.a"
  "../../../build_Windows/libMOTORINT.dll.manifest"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/MOTORINT.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
