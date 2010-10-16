/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkImageFileReader.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkImageFileReader - Reads common image formats.
// .SECTION Description
// vtkImageFileReader attempts to determine which kind of image is stored
// in a file and reads it using the appropriate reader.

#ifndef __vtkImageFileReader_h
#define __vtkImageFileReader_h

#include "vtkImageAlgorithm.h"

class vtkImageFileReader : public vtkImageAlgorithm
{
public:
  static vtkImageFileReader *New();
  vtkTypeMacro(vtkImageFileReader,vtkImageAlgorithm);
  void PrintSelf(ostream& os, vtkIndent indent);

  // Description:
  // Specify the name of the file to write out.
  vtkSetStringMacro(FileName);
  vtkGetStringMacro(FileName);

  int RequestData(vtkInformation *, vtkInformationVector **, vtkInformationVector *);

protected:
  vtkImageFileReader();
  ~vtkImageFileReader();

private:
  vtkImageFileReader(const vtkImageFileReader&);  // Not implemented.
  void operator=(const vtkImageFileReader&);  // Not implemented.

  char *FileName;
};

#endif