<template>
  <div class="input__container">
    <div
      class="no-file"
      :class="{ 'no-file--dropzone': isDragging }"
      @dragenter="isDragging = true"
      @dragleave="isDragging = false"
      @dragover.prevent
      @drop.prevent
      @drop="onFileDrop"
    >
      <i class="fas fa-file-alt file__icon"></i>
      <p>Drag and drop, or <span @click="onClickBrowse" class="no-file__link">browse</span></p>
    </div>
    <input type="file" ref="fileInput" class="file__input" @change="onFileInput">
  </div>
</template>

<script>
export default {
  name: 'FileUploader',

  data: () => ({
    fileName: null,
    isDragging: false,
  }),

  methods: {
    onClickBrowse() {
      this.$refs.fileInput.click();
    },

    onFileDrop(event) {
      this.isDragging = false;
      const textFile = event.dataTransfer?.files[0];

      if (textFile) {
        const reader = new FileReader();

        this.fileName = textFile.name;

        reader.readAsText(textFile);
        reader.onload = (e) => {
          const { result } = e.target;
          this.$emit('fileLoaded', result);
        };
      }
    },

    onFileInput(event) {
      const { files } = event.target;

      if (files.length) {
        const reader = new FileReader();
        const textFile = files[0];

        this.fileName = textFile.name;

        reader.readAsText(textFile);
        reader.onload = (e) => {
          const { result } = e.target;
          this.$emit('fileLoaded', result);
        };
      }
    },
  },
};
</script>

<style lang="scss" scoped>
.input__container {
  display: flex;
  justify-content: center;
  align-items: center;
  width: 100%;
  height: 160px;
  margin: 20px;
  max-width: 500px;

  .no-file {
    width: 90%;
    height: 100%;
    display: flex;
    flex-direction: column;
    justify-content: center;
    align-items: center;
    border-radius: 4px;
    border: 1px dashed rgb(212, 212, 212);
    font-weight: 500;
    transition: 0.3s;

    &.no-file--dropzone {
      background: rgb(212, 227, 255);
      border: 1px dashed rgb(164, 190, 238);
    }

    .file__icon {
      font-size: 26px;
      margin-bottom: 10px;
    }

    .no-file__link {
      cursor: pointer;
      text-decoration: underline;
    }
  }
}

.file__input {
  display: none;
}
</style>
