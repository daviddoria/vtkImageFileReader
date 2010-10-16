/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkImageFileReader.cxx

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/

#include "vtkImageFileReader.h"

#include "vtkSmartPointer.h"
#include "vtkInformationVector.h"
#include "vtkInformation.h"
#include "vtkObjectFactory.h"
#include "vtkImageData.h"
#include "vtkJPEGReader.h"
#include "vtkPNGReader.h"
#include "vtkBMPReader.h"
#include "vtkTIFFReader.h"

vtkStandardNewMacro(vtkImageFileReader);

vtkImageFileReader::vtkImageFileReader()
{
  this->FileName = NULL;

  this->SetNumberOfInputPorts(0);
}

vtkImageFileReader::~vtkImageFileReader()
{
  if ( this->FileName )
    {
    delete [] this->FileName;
    }
}

int vtkImageFileReader::RequestData(vtkInformation *vtkNotUsed(request),
                               vtkInformationVector **vtkNotUsed(inputVector),
                               vtkInformationVector *outputVector)
{
  // Get the info object
  vtkInformation *outInfo = outputVector->GetInformationObject(0);

  // Get the ouptut
  vtkImageData *output = vtkImageData::SafeDownCast(
      outInfo->Get(vtkDataObject::DATA_OBJECT()));

  vtkSmartPointer<vtkJPEGReader> jpegReader =
    vtkSmartPointer<vtkJPEGReader>::New();
  if(jpegReader->CanReadFile(this->FileName))
    {
    jpegReader->SetFileName(this->FileName);
    jpegReader->Update();
    output->ShallowCopy(jpegReader->GetOutput());

    // Without these lines, the output will appear real but will not work as the input to any other filters
    output->SetUpdateExtent(output->GetExtent());
    output->SetWholeExtent(output->GetExtent());

    return 1;
    }

  vtkSmartPointer<vtkPNGReader> pngReader =
    vtkSmartPointer<vtkPNGReader>::New();
  if(pngReader->CanReadFile(this->FileName))
    {
    pngReader->SetFileName(this->FileName);
    pngReader->Update();
    output->ShallowCopy(pngReader->GetOutput());

    // Without these lines, the output will appear real but will not work as the input to any other filters
    output->SetUpdateExtent(output->GetExtent());
    output->SetWholeExtent(output->GetExtent());

    return 1;
    }

  vtkSmartPointer<vtkBMPReader> bmpReader =
    vtkSmartPointer<vtkBMPReader>::New();
  if(bmpReader->CanReadFile(this->FileName))
    {
    bmpReader->SetFileName(this->FileName);
    bmpReader->Update();
    output->ShallowCopy(bmpReader->GetOutput());

    // Without these lines, the output will appear real but will not work as the input to any other filters
    output->SetUpdateExtent(output->GetExtent());
    output->SetWholeExtent(output->GetExtent());

    return 1;
    }

  vtkSmartPointer<vtkBMPReader> tiffReader =
    vtkSmartPointer<vtkBMPReader>::New();
  if(tiffReader->CanReadFile(this->FileName))
    {
    tiffReader->SetFileName(this->FileName);
    tiffReader->Update();
    output->ShallowCopy(tiffReader->GetOutput());

    // Without these lines, the output will appear real but will not work as the input to any other filters
    output->SetUpdateExtent(output->GetExtent());
    output->SetWholeExtent(output->GetExtent());

    return 1;
    }

  // If we get to here, we failed to read the image
  vtkErrorMacro(<< "Failed to read " << this->FileName);
  return -1;
}


void vtkImageFileReader::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os,indent);

  if (this->FileName)
    {
    os << indent << "FileName: " << this->FileName << "\n";
    }
  else
    {
    os << indent << "FileName: (null)\n";
    }
}

