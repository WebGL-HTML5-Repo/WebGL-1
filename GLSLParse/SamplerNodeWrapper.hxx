//--------------------------------------------------------------
//
// Microsoft Edge Implementation
// Copyright(c) Microsoft Corporation
// All rights reserved.
//
// MIT License
//
// Permission is hereby granted, free of charge, to any person obtaining
// a copy of this software and associated documentation files(the ""Software""),
// to deal in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and / or sell copies
// of the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions :
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED *AS IS*, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
// INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE AUTHORS
// OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
// WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
// OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//
//--------------------------------------------------------------
#pragma once

class VariableIdentifierNode;
class GLSLType;

//+-----------------------------------------------------------------------------
//
//  Class:      CDeclarationSamplerNodeWrapper
//
//  Synopsis:   Wrapper class for sampler/texture cloning. Derived classes
//              implement the logic specific to the nodes that they own.
//
//------------------------------------------------------------------------------
class CSamplerNodeWrapper
{
public:
    virtual void SetTypeQualifier() = 0;
    virtual UINT GetIdentifierCount() = 0;
    virtual VariableIdentifierNode* GetIdentifierNode(UINT uIndex) = 0;
    virtual HRESULT GetType(__deref_out GLSLType** ppType) const = 0;

    virtual HRESULT CreateNames(
        __in_z const char* pszCurrentName,              // The current GLSL name
        __inout CMutableString<char> &samplerName,      // Name of sampler var
        __inout CMutableString<char> &textureName,      // Name of texture var
        __inout CMutableString<char> &samplerSem,       // Semantic for sampler
        __inout CMutableString<char> &textureSem,       // Semantic for texture
        UINT uSamplerIndex                              // Index of texture
        ) = 0;
};
